// 用cvDFT()加快卷积的运算

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void speedy_convolution(const CvMat* A, const CvMat* B, CvMat* C) {
    int dft_M = cvGetOptimalDFTSize(A->rows + B->rows - 1);
    int dft_N = cvGetOptimalDFTSize(A->cols + B->cols - 1);

    CvMat *dft_A = cvCreateMat(dft_M, dft_N, A->type);
    CvMat *dft_B = cvCreateMat(dft_M, dft_N, B->type);
    CvMat tmp;

    // copy A to dft_A and pad dft_A with zeros
    cvGetSubRect(dft_A, &tmp, cvRect(0, 0, A->cols, A->rows));
    cvCopy(A, &tmp);
    cvGetSubRect(dft_A, &tmp, cvRect(A->cols, 0, dft_A->cols - A->cols, A->rows));
    cvZero(&tmp);

    cvDFT(dft_A, dft_A, CV_DXT_FORWARD, A->rows);

    cvGetSubRect(dft_B, &tmp, cvRect(0, 0, B->cols, B->rows));
    cvCopy(B, &tmp);
    cvGetSubRect(dft_B, &tmp, cvRect(B->cols, 0, dft_B->cols - B->cols, B->rows));
    cvZero(&tmp);

    cvDFT(dft_B, dft_B, CV_DXT_FORWARD, B->rows);

    cvMulSpectrums(dft_A, dft_B, dft_A, 0);

    // calculate only the top part
    cvDFT(dft_A, dft_A, CV_DXT_FORWARD, C->rows);
    cvGetSubRect(dft_A, &tmp, cvRect(0, 0, C->cols, C->rows));
    cvCopy(&tmp, C);
    cvReleaseMat(&dft_A);
    cvReleaseMat(&dft_B);
}
