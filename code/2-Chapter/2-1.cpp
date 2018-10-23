#include "opencv/cv.h"
#include "opencv/highgui.h"

int main() {
	IplImage *img = cvLoadImage("./Lena.jpg");
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
}
