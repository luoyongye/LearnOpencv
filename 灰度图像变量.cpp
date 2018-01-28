#include<stdlib.h>
#include<stdio.h>
#include<highgui.h>
#include<cv.h>
#include<cxcore.h>

using namespace cv;

 int main()
{	
	Mat InputImage = imread("grey.bmp");
	Mat disImage = InputImage.clone();
	int i,j;
	int cols = disImage.cols;
	int channels = disImage.channels();
	for(i=0;i<disImage.rows;i++)
	{
		uchar* data = disImage.ptr<uchar>(i); 
		uchar* data2 = InputImage.ptr<uchar>(i);
		for(j=0;j<(cols * channels);j++)
		{
			data[j] = data2[j]+20;
		}
	}
	namedWindow("show_src");
	namedWindow("show_light");
	imshow("show_src",InputImage);
	waitKey(0);
	imshow("show_light",disImage);
	waitKey(0);
	return 0;

}