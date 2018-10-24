//读取磁盘中的cfg.xml文件
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int main()
{
    CvFileStorage *fs = cvOpenFileStorage("cfg.xml", 0, CV_STORAGE_READ);
    int frame_count = cvReadIntByName(fs, 0, "frame_count", 5);
    CvSeq *s = cvGetFileNodeByName(fs, 0, "frame_size")->data.seq;
    int frame_width = cvReadInt((CvFileNode *) cvGetSeqElem(s, 0));
    int frame_height = cvReadInt((CvFileNode *) cvGetSeqElem(s, 1));
    cvReleaseFileStorage(&fs);
    cout << frame_count << "," << frame_width << "," << frame_height << endl;
    return 0;
}
