/*
//²ÊÉ«Í¼Ïñ±ä»»
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
    imshow("²¹É«HSV", colorpicture);
 //RGB
    colorpicture=Scalar::all(255)-image;
    imshow("RBGbuse", colorpicture);
}
*/