// 极坐标变换

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    IplImage *src;
    double M;
    src = cvLoadImage("cameraman.png", 1);
    M = 2.0;
    IplImage *dst = cvCreateImage(cvGetSize(src), 8, 3);
    IplImage *src2 = cvCreateImage(cvGetSize(src), 8, 3);
    cvLogPolar(src, dst, cvPoint2D32f(src->width / 4, src->height / 2), M, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
    cvLogPolar(dst, src2, cvPoint2D32f(src->width / 4, src->height / 2), M, CV_INTER_LINEAR | CV_WARP_INVERSE_MAP);
    cvNamedWindow("log-polar", 1);
    cvShowImage("log-polar", dst);
    cvNamedWindow("inverse log-polar", 1);
    cvShowImage("inverse log-polar", src2);
    cvWaitKey();
    return 0;
}
