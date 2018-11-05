#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void sum_rgb(IplImage* src, IplImage* dst) {
    IplImage *r = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    IplImage *g = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    IplImage *b = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

    cvSplit(src, r, g, b, NULL);
    IplImage *s = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);

    cvAddWeighted(r, 1. / 3., g, 1. / 3., 0.0, s);
    cvAddWeighted(s, 2. / 3., b, 1. / 2., 0.0, s);

    cvThreshold(s, dst, 100, 100, CV_THRESH_TRUNC);
    cvReleaseImage(&r);
    cvReleaseImage(&g);
    cvReleaseImage(&b);
    cvReleaseImage(&s);
}

int main() {
    cvNamedWindow("Demo");
    IplImage *src = cvLoadImage("cameraman.png");
    IplImage *dst = cvCreateImage(cvGetSize(src), src->depth, 1);
    sum_rgb(src, dst);

    cvShowImage("Demo", dst);

    while(1) {
        if ((cvWaitKey(10) & 0x7f) == 27)
            break;
    }
    cvDestroyWindow("Demo");
    cvReleaseImage(&src);
    cvReleaseImage(&dst);
    return 0;
}
