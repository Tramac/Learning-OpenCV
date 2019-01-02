// 在输入图像上寻找并绘制轮廓

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

IplImage *g_image = NULL;
IplImage *g_gray = NULL;
int g_thresh = 100;
CvMemStorage *g_storage = NULL;

void on_trackbar(int) {
    if (g_storage == NULL) {
        g_gray = cvCreateImage(cvGetSize(g_image), 8, 1);
        g_storage = cvCreateMemStorage(0);
    }
    else {
        cvClearMemStorage(g_storage);
    }
    CvSeq *contours = 0;
    cvCvtColor(g_image, g_gray, CV_THRESH_BINARY);
    cvThreshold(g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY);
    cvFindContours(g_gray, g_storage, &contours);
    cvZero(g_gray);
    if (contours) {
        cvDrawContours(
            g_gray,
            contours,
            cvScalarAll(255),
            cvScalarAll(255),
            100
        );
    }
    cvShowImage("Contours", g_gray);
}

int main(int argc, char** argv) {
    g_image = cvLoadImage("Lena.jpg");
    cvNamedWindow("Contours", 1);
    cvCreateTrackbar(
        "Threshold",
        "Contours",
        &g_thresh,
        255,
        on_trackbar
    );
    on_trackbar(0);
    cvWaitKey(0);
    return 0;
}
