/*
//处理为灰度图像
void grayShow(Mat& image) {
    Mat gray;
    cvtColor(image, gray, COLOR_RGBA2GRAY);
    namedWindow("gray picture");
    imshow("gray picture", gray);
    Threshold(gray);
    //logTransfer(gray);
    //gammaTranfer(gray);
}
//二值化变换
void Threshold(Mat &gray) {
    Mat result;
    threshold(gray, result, 120,255,THRESH_BINARY);
    namedWindow("binary picture");
    imshow("binary picture", result);
}
*/