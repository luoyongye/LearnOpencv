#include <iostream>  
#include <opencv2\core\core.hpp>  
#include <opencv2\highgui\highgui.hpp>  
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

void linearityOpr(Mat src, Mat &dst, float slope, float intercept)
{
	int M = 0;
	int N = 0;
	if (src.empty()) {
		std::cout << "Src pic is empty\n" << std::endl;
		return;
	}
	M = src.rows;
	N = src.cols;
	int j = 0;
	float gray = 0;
	for (int i = 0;i < M;i++) {
		for (j = 0; j < N; j++) {
			gray = (float)src.at<uchar>(i, j);
			gray = slope*((float)(1 + gray)) + intercept;
			dst.at<uchar>(i, j) = saturate_cast<uchar>(gray);
		}
	}
}

void EnhanceImage(Mat &originalImage)
{
	double now = getTickCount();
	//��  
	int rows = originalImage.rows;
	int col = originalImage.cols;
	//ÿ����Ԫ���������˴�ͼ��Ϊ3ͨ��  

	//���ѭ��ִֻ��һ��  
	for (int i = 0;i<rows;i++)
	{
		for (int j = 0;j<col;j++)
		{
			if ((originalImage.at<Vec3b>(i, j)[0] > originalImage.at<Vec3b>(i, j)[1]) && (originalImage.at<Vec3b>(i, j)[0]> originalImage.at<Vec3b>(i, j)[2]))
			{
				originalImage.at<Vec3b>(i, j)[0] =255;
				originalImage.at<Vec3b>(i, j)[1] = 255;
				originalImage.at<Vec3b>(i, j)[2] = 255;
			}
			else
			{
				originalImage.at<Vec3b>(i, j)[0] *= 0;
				originalImage.at<Vec3b>(i, j)[1] = 0;
				originalImage.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}
}


uchar toZero(uchar a);//���㺯����С������Ϊ0  
int main()
{
	Mat mat = imread("3.bmp");
	namedWindow("��ʴǰ");

	//Mat mergeImg;//�ϲ����ͼ��  
				 //�����洢��ͨ��ͼƬ������  
	//vector<Mat> splitBGR(mat.channels());
	//�ָ�ͨ�����洢��splitBGR��  
	//split(mat, splitBGR);
	//�Ը���ͨ���������Ե�����
	/*for (int i = 0; i<mat.channels(); i++)
		linearityOpr(splitBGR[i], splitBGR[i], 4, -765);*/
	//�ϲ�ͨ��  
	//merge(splitBGR, mergeImg);

	//mat=mergeImg;
	EnhanceImage(mat);

	imshow("��ʴǰ", mat);
	waitKey(0);

	//��ʴ����
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dstImage;
	erode(mat, dstImage, element);
	imshow("��Ч��ͼ����ʴ����", dstImage);
	waitKey(0);

	//���Ͳ���
	Mat element2 = getStructuringElement(MORPH_RECT, Size(3,3));
	Mat dstImage2;
	dilate(dstImage,dstImage2,element2);
	imshow("��Ч��ͼ����ʴ�������Ͳ���", dstImage2);
	waitKey(0);

	

	/*
	Mat  result1, result2;
	result1 = mat.clone();
	result2 = mergeImg.clone();

	int rowNumber = result1.rows;
	int colNumber = result1.cols;
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < colNumber; j++)
		{
			result1.at<Vec3b>(i, j)[0] = toZero(mergeImg.at<Vec3b>(i, j)[0] - mat.at<Vec3b>(i, j)[0]);
			result1.at<Vec3b>(i, j)[1] = toZero(mergeImg.at<Vec3b>(i, j)[1] - mat.at<Vec3b>(i, j)[1]);
			result1.at<Vec3b>(i, j)[2] = toZero(mergeImg.at<Vec3b>(i, j)[2] - mat.at<Vec3b>(i, j)[2]);
		}
	}
	//addWeighted��������ͼ�����  
	addWeighted(mergeImg, 1, mat, -1, 0, result2);
	imshow("result1", result1);
	imshow("addWeighted", result2);
	waitKey();
	*/
	return 0;
}

uchar toZero(uchar a)
{
	if (a < 0)
		return 0;
	else
		return a;
}