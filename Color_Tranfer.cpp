/*
//��ɫͼ��任
void Color_Transfer(Mat &image) {
    Mat colorpicture;
    image.copyTo(colorpicture);
   //HSV
    Mat hsvImg;
    cvtColor(image,hsvImg, COLOR_BGR2HSV);
    std::vector<Mat> hsv;
    split(hsvImg, hsv);
    hsv[0]=(Scalar::all(180)-hsv[0]);
    merge(hsv, colorpicture);
    imshow("��ɫHSV", colorpicture);
 //RGB
    colorpicture=Scalar::all(255)-image;
    imshow("RBGbuse", colorpicture);
}
*/