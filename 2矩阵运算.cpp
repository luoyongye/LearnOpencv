#include<stdlib.h>
#include<stdio.h>
#include<highgui.h>
#include<cv.h>
#include<cxcore.h>

int main(int argc,char*argv[])
{
	//��������A
	double a[]= {1,2,3,
	             4,5,6};
	CvMat* A = cvCreateMat(2,3,CV_64FC1);
	cvInitMatHeader(A,2,3,CV_64FC1,a);

	//��������B
	double b[]= {10,20,30,
	             40,50,60};
	CvMat* B = cvCreateMat(2,3,CV_64FC1);
	cvInitMatHeader(B,2,3,CV_64FC1,b);

	//��ֵ����A,����AA
	CvMat* AA = cvCloneMat(A);

	//add = A+B
	CvMat* add = cvCreateMat(2,3,CV_64FC1);
	cvAdd(A,B,add);

	//sub = A-B
	CvMat* sub = cvCreateMat(2,3,CV_64FC1);
	cvSub(A,B,sub);

	
	//��ʾA
	printf("A = \n");
	for (int x=0;x<A->rows;x++)
	{
		for (int y=0;y<A->cols;y++)
		{
			float value = cvmGet(A,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}

	//��ʾB
	printf("\nB = \n");
	for (int x=0;x<B->rows;x++)
	{
		for (int y=0;y<B->cols;y++)
		{
			float value = cvmGet(B,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}

	//��ʾAA
	printf("\nAA = \n");
	for (int x=0;x<AA->rows;x++)
	{
		for (int y=0;y<AA->cols;y++)
		{
			float value = cvmGet(AA,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}

	//��ʾadd
	printf("\nadd = \n");
	for (int x=0;x<add->rows;x++)
	{
		for (int y=0;y<add->cols;y++)
		{
			float value = cvmGet(add,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}

	//��ʾsub
	printf("\nsub = \n");
	for (int x=0;x<sub->rows;x++)
	{
		for (int y=0;y<sub->cols;y++)
		{
			float value = cvmGet(sub,x,y);
			printf("%f  ",value);
		}
		printf("\n");
	}

	getchar();
	return 0;
}