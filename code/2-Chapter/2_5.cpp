#include "opencv/cv.h"
#include "opencv/highgui.h"

IplImage* doPyrDown(IplImage* in, int filter=IPL_GAUSSIAN_5x5) {
    assert(in->width % 2 == 0 && in->height % 2 == 0);
    IplImage *out = cvCreateImage(
        cvSize(in->width / 2, in->height / 2),
        in->depth,
        in->nChannels);
    cvPyrDown(in, out);
    return(out);
}
