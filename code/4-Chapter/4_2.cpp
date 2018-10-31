// 使用滑动条实现开关功能
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;

int g_switch_value = 0;

void switch_off_function() {
    cout << "off" << endl;
}

void switch_on_function() {
    cout << "on" << endl;
}

void switch_callback(int position) {
    if (position == 0) {
        switch_off_function();
    }
    else {
        switch_on_function();
    }
}

int main() {
    cvNamedWindow("Demo Window", 1);
    cvCreateTrackbar("Switch", "Demo Window", &g_switch_value, 1, switch_callback);
    while (1) {
        if (cvWaitKey(15) == 27)
            break;
    }
    return 0;
}
