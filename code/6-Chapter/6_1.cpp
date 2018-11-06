//使用cvHoughCircles返回在灰度图像中找到的圆序列
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    IplImage *image = cvLoadImage("cameraman.png", CV_LOAD_IMAGE_GRAYSCALE);

    CvMemStorage *storage = cvCreateMemStorage(0);
    cvSmooth(image, image, CV_GAUSSIAN, 5, 5);

    CvSeq *results = cvHoughCircles(image, storage, CV_HOUGH_GRADIENT, 2, image->width / 10);
    for (int i = 0; i < results->total; i++) {
        float *p = (float *)cvGetSeqElem(results, i);
        CvPoint pt = cvPoint(cvRound(p[0]), cvRound(p[1]));
        cvCircle(image, pt, cvRound(p[2]), CV_RGB(0xff, 0xff, 0xff));
    }
    cvNamedWindow("cvHoughCircles", 1);
    cvShowImage("cvHoughCircles", image);
    cvWaitKey(0);
    return 0;
}
