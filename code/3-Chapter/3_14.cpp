//sec2中alpha融合ROI以(0,0)开始，src1中ROI以（x,y）开始
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int main()
{
    IplImage* src1 = cvLoadImage("./cameraman.png");
    IplImage *src2 = cvLoadImage("./parrot.png");
    int x = 50;
    int y = 50;
    int width = 150;
    int height = 150;
    double alpha = 0.0;
    double beta = 1.0;
    cvSetImageROI(src1, cvRect(x, y, width, height));
    cvSetImageROI(src2, cvRect(0, 0, width, height));
    cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);
    cvResetImageROI(src1);
    cvNamedWindow("Alpha_blend", 1);
    cvShowImage("Alpha_blend", src1);
    cvWaitKey();
    return 0;
}
