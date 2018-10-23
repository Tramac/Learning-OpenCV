//Canny边缘检测
IplImage* doCanny(IplImage* in, double lowThresh, double heighThresh, double aperture) {
    if(in->nChannels != 1) {
        return 0;
    }
    IplImage *out = cvCreateImage(
        cvSize(cvGetSize(in)),
        IPL_DEPTH_8U,
        1);
    cvCanny(in, out, lowThresh, heighThresh, aperture);
    return out;
}
