/*	
  功能：读入图像文件，并将图像显示在屏幕上
*/
#include "cv.h"
#include "highgui.h"
int main( int argc, char** argv )
{
    IplImage* src; //声明IplImage指针
    //载入图像
    src = cvLoadImage("img166.bmp",-1);//src = cvLoadImage("F:\\img166.bmp",-1);
    cvNamedWindow( "Image", 1 ); //创建窗口
    cvShowImage( "Image", src ); //显示图像
    cvWaitKey(0); //等待按键
    cvDestroyWindow( "Image" );//销毁窗口
    cvReleaseImage( &src ); //释放图像
    return 0;
   
}
