#include"stdio.h"
#include "cv.h"
#include "cxcore.h"
#include "cxtypes.h"
#include "highgui.h"

int main()
{
	// Load an image from file
	IplImage *src = cvLoadImage("C:\\Users\\zh'b\\Pictures\\Cyberpunk 2077\\photomode_17022024_140826.png", 1);
	int height = src->height;
	int width = src->width;
	cvNamedWindow("Source", 1);
	cvShowImage("Source", src);

	//转换色彩空间
	IplImage *HSV_Image = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);//为HSV图像分配空间
	cvCvtColor(src, HSV_Image, CV_BGR2HSV);//颜色空间转换为HSV

	cvNamedWindow("HSV_Image", 1);
	cvShowImage("HSV_Image", HSV_Image);

	//分离通道
	IplImage *R_Channel = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	IplImage *G_Channel = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	IplImage *B_Channel = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	cvSplit(src, B_Channel, G_Channel, R_Channel, NULL);

	cvNamedWindow("R_Channel", 1);
	cvShowImage("R_Channel", R_Channel);
	cvNamedWindow("G_Channel", 1);
	cvShowImage("G_Channel", G_Channel);
	cvNamedWindow("B_Channel", 1);
	cvShowImage("B_Channel", B_Channel);
	



	cvWaitKey(0);

}
