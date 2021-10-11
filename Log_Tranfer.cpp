/*
//对数变换
void Log_Transfer(Mat &gray){
    Mat srcImage(gray);
    Mat dstImage(srcImage.size(),srcImage.type());
    //计算1+r
    add(gray, Scalar(1.0), srcImage);
    //转换为浮点数
    srcImage.convertTo(srcImage, CV_64F);
    //计算log(1+r) log:第一个参数为输入图像，第二个参数为得到的对数值
    log(srcImage,dstImage);
    //这里设c=1
    dstImage=1*dstImage;
    //归一化处理
    normalize(dstImage,dstImage,0,255,NORM_MINMAX);
    convertScaleAbs(dstImage, dstImage);
    imshow("dstpicture", dstImage);
}
*/