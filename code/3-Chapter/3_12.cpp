// 用imageROI来增加某范围的像素
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int main()
{
    IplImage* src = cvLoadImage("./Lena.jpg");
    int x = 25;
    int y = 25;
    int width = 100;
    int height = 100;
    int add = 150;
    cvSetImageROI(src, cvRect(x, y, width, height));
    cvAddS(src, cvScalar(add), src);
    cvResetImageROI(src);
    cvNamedWindow("Roi_Add", 1);
    cvShowImage("Roi_Add", src);
    cvWaitKey(0);
    return 0;
}
