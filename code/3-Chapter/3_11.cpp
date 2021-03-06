// 仅最大化HSV图像S和V部分
void saturate_sv(IplImage* img) {
    for (int y = 0; y < img->height; y++) {
        uchar *ptr = (uchar *)(img->imageData + y * img->widthStep);
        for (int x = 0; x < img->width; x++) {
            ptr[3 * x + 1] = 255;
            ptr[3 * x + 2] = 255;
        }
    }
}
