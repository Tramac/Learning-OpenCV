//往磁盘上写一个配置文件cfg.xml
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int main()
{
    CvFileStorage *fs = cvOpenFileStorage("cfg.xml", 0, CV_STORAGE_WRITE);
    cvWriteInt(fs, "frame_count", 10);
    cvStartWriteStruct(fs, "frame_size", CV_NODE_SEQ);
    cvWriteInt(fs, 0, 320);
    cvWriteInt(fs, 0, 200);
    cvEndWriteStruct(fs);
    //cvWrite(fs, "color_cvt_matrix", cmatrix);
    cvReleaseFileStorage(&fs);
    return 0;
}
