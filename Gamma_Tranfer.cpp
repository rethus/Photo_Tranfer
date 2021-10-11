/*
 //伽马变换
    //gamma值，随着值不同图片呈现出不同的效果
void Gamma_Tranfer(Mat &gray) {
    //gamma值，随着值不同图片呈现出不同的效果
    double gamma=0.5;
    Mat grayImg;
    gray.convertTo(grayImg, CV_64F,1.0/255,0);
    Mat gammaImg;
    pow(grayImg, gamma,gammaImg);
    gammaImg.convertTo(gammaImg, CV_8U,255,0);
    imshow("gammapicture", gammaImg);

}
*/