/*
//�����任
void Log_Transfer(Mat &gray){
    Mat srcImage(gray);
    Mat dstImage(srcImage.size(),srcImage.type());
    //����1+r
    add(gray, Scalar(1.0), srcImage);
    //ת��Ϊ������
    srcImage.convertTo(srcImage, CV_64F);
    //����log(1+r) log:��һ������Ϊ����ͼ�񣬵ڶ�������Ϊ�õ��Ķ���ֵ
    log(srcImage,dstImage);
    //������c=1
    dstImage=1*dstImage;
    //��һ������
    normalize(dstImage,dstImage,0,255,NORM_MINMAX);
    convertScaleAbs(dstImage, dstImage);
    imshow("dstpicture", dstImage);
}
*/