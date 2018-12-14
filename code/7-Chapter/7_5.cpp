// 模板匹配

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    IplImage *src, *temp1, *ftmp[6];
    int i;
    src = cvLoadImage("cameraman.png", 1);
    temp1 = cvLoadImage("parrot.png", 1);

    int iwidth = src->width - temp1->width + 1;
    int iheight = src->height - temp1->height + 1;
    for (i = 0; i < 6; ++i) {
        ftmp[i] = cvCreateImage(cvSize(iwidth, iheight), 32, 1);
    }
    for (i = 0; i < 6; ++i) {
        cvMatchTemplate(src, temp1, ftmp[i], i);
        cvNormalize(ftmp[i], ftmp[i], 1, 0, CV_MINMAX);
    }
    cvNamedWindow("Template", 0);
    cvShowImage("Template", temp1);
    cvNamedWindow("Image", 0);
    cvShowImage("Image", src);
    cvNamedWindow("SQDIFF", 0);
    cvShowImage("SQDIFF", ftmp[0]);
    cvNamedWindow("SQDIFF_NORMED", 0);
    cvShowImage("SQDIFF_NORMED", ftmp[1]);
    cvNamedWindow("CCORR", 0);
    cvShowImage("CCORR", ftmp[2]);
    cvNamedWindow("CCORR_NORMED", 0);
    cvShowImage("CCORR_NORMED", ftmp[3]);
    cvNamedWindow("CCOEFF", 0);
    cvShowImage("CCOEFF", ftmp[4]);
    cvNamedWindow("CCOEFF_NORMED", 0);
    cvShowImage("CCOEFF_NORMED", ftmp[5]);
    cvWaitKey(0);

    return 0;
}
