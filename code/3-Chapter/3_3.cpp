//利用固定数据创建一个CvMat
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int main() {
    float vals[] = {0.866025, -0.500000, 0.500000, 0.866025};
    CvMat rotmat;
    cvInitMatHeader(&rotmat,2,2,CV_32FC1,vals);
    int tp = cvGetElemType(&rotmat);
    cout << tp << endl;
    return 0;
}
