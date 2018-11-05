#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    double threshold = double(15);
    int threshold_type = int(1) ? CV_THRESH_BINARY : CV_THRESH_BINARY_INV;
    int adaptive_method = int(1) ? CV_ADAPTIVE_THRESH_MEAN_C : CV_ADAPTIVE_THRESH_GAUSSIAN_C;
    int block_size = int(71);
    double offset = (double)(15);

    IplImage* Igray = cvLoadImage("cameraman.png", CV_LOAD_IMAGE_GRAYSCALE);
    IplImage* It = cvCreateImage(cvSize(Igray->width, Igray->height), IPL_DEPTH_8U, 1);
    IplImage *Iat = cvCreateImage(cvSize(Igray->width, Igray->height), IPL_DEPTH_8U, 1);

    cvThreshold(Igray, It, threshold, 255, threshold_type);
    cvAdaptiveThreshold(Igray, Iat, 255, adaptive_method, threshold_type, block_size, offset);

    cvNamedWindow("Raw", 1);
    cvNamedWindow("Threshold", 1);
    cvNamedWindow("Adaptive Threshold", 1);
    cvShowImage("Raw", Igray);
    cvShowImage("Threshold", It);
    cvShowImage("Adaptive Threshold", Iat);

    cvWaitKey(0);
    cvReleaseImage(&Igray);
    cvReleaseImage(&It);
    cvReleaseImage(&Iat);
    cvDestroyWindow("Raw");
    cvDestroyWindow("Threshold");
    cvDestroyWindow("Adaptive Threshold");
    return 0;
}
