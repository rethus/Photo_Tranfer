/*
 //٤��任
    //gammaֵ������ֵ��ͬͼƬ���ֳ���ͬ��Ч��
void Gamma_Tranfer(Mat &gray) {
    //gammaֵ������ֵ��ͬͼƬ���ֳ���ͬ��Ч��
    double gamma=0.5;
    Mat grayImg;
    gray.convertTo(grayImg, CV_64F,1.0/255,0);
    Mat gammaImg;
    pow(grayImg, gamma,gammaImg);
    gammaImg.convertTo(gammaImg, CV_8U,255,0);
    imshow("gammapicture", gammaImg);

}
*/