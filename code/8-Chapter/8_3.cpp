#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

#define CVX_RED CV_RGB(0xff, 0x00, 0x00)
#define CVX_GREEN CV_RGB(0x00, 0xff, 0x00)
#define CVX_BLUE CV_RGB(0x00, 0x00, 0xff)

int main() {
    cvNamedWindow("Origin", 1);
    IplImage *img_8uc1 = cvLoadImage("Lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    IplImage *img_edge = cvCreateImage(cvGetSize(img_8uc1), 8, 1);
    IplImage *img_8uc3 = cvCreateImage(cvGetSize(img_8uc1), 8, 3);
    cvThreshold(img_8uc1, img_edge, 128, 255, CV_THRESH_BINARY);
    CvMemStorage *storage = cvCreateMemStorage();
    CvSeq *first_counter = NULL;
    int Nc = cvFindContours(
        img_edge,
        storage,
        &first_counter,
        sizeof(CvContour),
        CV_RETR_LIST);
    int n = 0;
    printf("Total Contours Detected: %d\n", Nc);
    cvCvtColor(img_8uc1, img_8uc3, CV_GRAY2BGR);
    for (CvSeq *c = first_counter; c != NULL; c = c->h_next) {
        cvDrawContours(
            img_8uc3,
            c,
            CVX_RED,
            CVX_BLUE,
            0, 2,
            8);
        printf("Countour #%d\n", n);
        cvShowImage("Origin", img_8uc3);
        printf("%d elements:\n", c->total);
        for (int i = 0; i < c->total; ++i) {
            CvPoint *p = CV_GET_SEQ_ELEM(CvPoint, c, i);
            printf(" (%d, %d)\n", p->x, p->y);
        }
        if (cvWaitKey() == 27)
            break;
        n++;
    }

    printf("Fineshed all contours.\n");
    cvCvtColor(img_8uc1, img_8uc3, CV_GRAY2BGR);
    cvShowImage("Origin", img_8uc3);
    cvWaitKey(0);
    cvDestroyWindow("Origin");
    cvReleaseImage(&img_8uc1);
    cvReleaseImage(&img_8uc3);
    cvReleaseImage(&img_edge);
    return 0;
}
