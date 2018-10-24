#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int main()
{
    IplImage* interest_img = cvLoadImage("./Lena.jpg");
    CvRect interest_rect = cvRect(30, 30, 100, 100);
    IplImage *sub_img = cvCreateImageHeader(cvSize(interest_rect.width, interest_rect.height), 
                                            interest_img->depth, 
                                            interest_img->nChannels);
    sub_img->origin = interest_img->origin;
    sub_img->widthStep = interest_img->widthStep;
    sub_img->imageData = interest_img->imageData + 
                         interest_rect.y * interest_img->widthStep + 
                         interest_rect.x * interest_img->nChannels;
    cvAddS(sub_img, cvScalar(100), sub_img);
    cvNamedWindow("Roi_Add", 1);
    cvShowImage("Roi_Add", sub_img);
    cvWaitKey(0);
    return 0;
}
