// 累加一个三通道矩阵中的所有元素
float sum(const CvMat* mat) {
    float s = 0.0f;
    for (int row = 0; row < mat->rows; row++) {
        const float *ptr = (const float *)(mat->data.ptr + row * mat->step);
        for (int col = 0; col < mat->cols; col++) {
            s += *ptr++;
        }
    }
    return s;
}
