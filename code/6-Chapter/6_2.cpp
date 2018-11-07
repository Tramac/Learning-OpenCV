// 仿射变换

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    CvPoint2D32f srcTri[3], dstTri[3];
    CvMat *rot_mat = cvCreateMat(2, 3, CV_32FC1);
    CvMat *warp_mat = cvCreateMat(2, 3, CV_32FC1);
    IplImage *src, *dst;
    src = cvLoadImage("cameraman.png", 1);
    dst = cvCloneImage(src);
    dst->origin = src->origin;
    cvZero(dst);

    // Compute warp matrix
    srcTri[0].x = 0;
    srcTri[0].y = 0;
    srcTri[1].x = src->width - 1;
    srcTri[1].y = 0;
    srcTri[2].x = 0;
    srcTri[2].y = src->height - 1;
    dstTri[0].x = src->width * 0.0;
    dstTri[0].y = src->height * 0.33;
    dstTri[1].x = src->width * 0.85;
    dstTri[1].y = src->height * 0.25;
    dstTri[2].x = src->width * 0.15;
    dstTri[2].y = src->height * 0.7;

    cvGetAffineTransform(srcTri, dstTri, warp_mat);
    cvWarpAffine(src, dst, warp_mat);
    cvCopy(dst, src);

    // Compute rotation matrix
    CvPoint2D32f center = cvPoint2D32f(src->width / 2, src->height / 2);
    double angle = -50.0;
    double scale = 0.6;
    cv2DRotationMatrix(center, angle, scale, rot_mat);

    // Do the transformation
    cvWarpAffine(src, dst, rot_mat);
    cvNamedWindow("Affine_Transform", 1);
    cvShowImage("Affine_Transform", dst);
    cvWaitKey();
    cvReleaseImage(&dst);
    cvReleaseMat(&rot_mat);
    cvReleaseMat(&warp_mat);
    return 0;
}
