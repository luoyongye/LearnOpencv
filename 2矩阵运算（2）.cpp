#include<stdlib.h>
#include<stdio.h>
#include<highgui.h>
#include<cv.h>
#include<cxcore.h>

int main(int argc,char*argv[])
{
	//��������
	double a[]= {1,10,101,2,20,102,3,30,103,
				 4,40,104,5,50,105,6,60,106};
	CvMat* M = cvCreateMat(2,3,CV_64FC3);
	cvInitMatHeader(M,2,3,CV_64FC3,a);
	
	//����ͼ��
	IplImage* img = cvCreateImage(cvGetSize(M),8,3);

	//����ͼ��
    cvGetImage(M,img);
	cvSaveImage("img.bmp",img);
	cvReleaseMat(&M);

	IplImage* src = cvLoadImage("img.bmp");
	
	//����CvScalar�ṹ�壬����Ϊs1���洢��ȡ����ֵ
	CvScalar s1;
	double s2[3],s3[3];

	//��ȡ��i��j)λ�õ���ֵ
	int i = 1;
	int j = 1;

	
	//����һ����ӷ�ʽ
    s1 = cvGet2D(src,i,j); // get the (i,j) pixel value
    printf("����һ��(%f,%f,%f)\n",s1.val[0],s1.val[1],s1.val[2]);

	//��������ֱ�ӷ�ʽ
	s2[0] = ((uchar *)(src->imageData + i*src->widthStep))[j*3];
	s2[1] = ((uchar *)(src->imageData + i*src->widthStep))[j*3+1];
	s2[2] = ((uchar *)(src->imageData + i*src->widthStep))[j*3+2];
	printf("��������(%f,%f,%f)\n",s2[0],s2[1],s2[2]);
	

	//��������ָ��ֱ�ӷ���
	int step        = src->widthStep/sizeof(uchar);
    uchar* data     = (uchar *)src->imageData;
    s3[0] = data[i*step+j*3], s3[1] = data[i*step+j*3+1], s3[2] = data[i*step+j*3+2];
	printf("��������(%f,%f,%f)\n",s3[0],s3[1],s3[2]);

	cvReleaseImage(&src);
	cvDestroyWindow("ԭͼ");
	getchar();
	 return 0;
}