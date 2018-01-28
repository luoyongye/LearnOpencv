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
	//行  
	int rows = originalImage.rows;
	int col = originalImage.cols;
	//每行总元素数量，此处图像为3通道  

	//外层循环只执行一次  
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


uchar toZero(uchar a);//置零函数，小于零则为0  
int main()
{
	Mat mat = imread("3.bmp");
	namedWindow("腐蚀前");

	//Mat mergeImg;//合并后的图像  
				 //用来存储各通道图片的向量  
	//vector<Mat> splitBGR(mat.channels());
	//分割通道，存储到splitBGR中  
	//split(mat, splitBGR);
	//对各个通道进行线性点运算
	/*for (int i = 0; i<mat.channels(); i++)
		linearityOpr(splitBGR[i], splitBGR[i], 4, -765);*/
	//合并通道  
	//merge(splitBGR, mergeImg);

	//mat=mergeImg;
	EnhanceImage(mat);

	imshow("腐蚀前", mat);
	waitKey(0);

	//腐蚀操作
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dstImage;
	erode(mat, dstImage, element);
	imshow("【效果图】腐蚀操作", dstImage);
	waitKey(0);

	//膨胀操作
	Mat element2 = getStructuringElement(MORPH_RECT, Size(3,3));
	Mat dstImage2;
	dilate(dstImage,dstImage2,element2);
	imshow("【效果图】腐蚀后再膨胀操作", dstImage2);
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
	//addWeighted方法进行图像相减  
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