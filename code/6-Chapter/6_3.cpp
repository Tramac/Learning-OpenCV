// 密集透视变换

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    CvPoint2D32f srcQuad[4], dstQuad[4];
    CvMat *warp_matrix = cvCreateMat(3, 3, CV_32FC1);
    IplImage *src, *dst;
    src = cvLoadImage("cameraman.png", 1);
    dst = cvCloneImage(src);
    dst->origin = src->origin;
    cvZero(dst);

    srcQuad[0].x = 0;
    srcQuad[0].y = 0;
    srcQuad[1].x = src->width - 1;
    srcQuad[1].y = 0;
    srcQuad[2].x = 0;
    srcQuad[2].y = src->height - 1;
    srcQuad[3].x = src->width - 1;
    srcQuad[3].y = src->height - 1;
    dstQuad[0].x = src->width * 0.05;
    dstQuad[0].y = src->height * 0.33;
    dstQuad[1].x = src->width * 0.9;
    dstQuad[1].y = src->height * 0.25;
    dstQuad[2].x = src->width * 0.2;
    dstQuad[2].y = src->height * 0.7;
    dstQuad[3].x = src->width * 0.8;
    dstQuad[3].y = src->height * 0.9;

    cvGetPerspectiveTransform(srcQuad, dstQuad, warp_matrix);
    cvWarpPerspective(src, dst, warp_matrix);
    cvNamedWindow("Perspective_Warp", 1);
    cvShowImage("Perspective_Warp", dst);
    cvWaitKey();

    cvReleaseImage(&dst);
    cvReleaseMat(&warp_matrix);
    return 0;
}
