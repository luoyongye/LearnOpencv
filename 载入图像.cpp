/*	
  ���ܣ�����ͼ���ļ�������ͼ����ʾ����Ļ��
*/
#include "cv.h"
#include "highgui.h"
int main( int argc, char** argv )
{
    IplImage* src; //����IplImageָ��
    //����ͼ��
    src = cvLoadImage("img166.bmp",-1);//src = cvLoadImage("F:\\img166.bmp",-1);
    cvNamedWindow( "Image", 1 ); //��������
    cvShowImage( "Image", src ); //��ʾͼ��
    cvWaitKey(0); //�ȴ�����
    cvDestroyWindow( "Image" );//���ٴ���
    cvReleaseImage( &src ); //�ͷ�ͼ��
    return 0;
   
}
