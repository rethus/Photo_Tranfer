#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define BMPNAME_FOR_READ "test1.bmp"
#define BMPNAME_FOR_SAVE "new_test1.bmp"

typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;

unsigned char* pBmpBuf;
int BMP_Width;
int BMP_Height;
int biBitCount;//像素位数
RGBQUAD* pColorTable;//颜色表指针

bool BMP_Read(char* BMP_Name) {
    FILE* fp = fopen(BMP_Name, "rb");//打开
    if (fp == NULL) return false;//打开失败

    fseek(fp, sizeof(BITMAPFILEHEADER), 0);//确保指针移到最开始

    BITMAPINFOHEADER head;
    fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
    BMP_Width = head.biWidth;
    BMP_Height = head.biHeight;
    biBitCount = head.biBitCount;

    int lineByte = (BMP_Width * biBitCount / 8 + 3) / 4 * 4;//4的倍数

    //颜色
    if (biBitCount == 8) {
        pColorTable = new RGBQUAD[256];
        fread(pColorTable, sizeof(RGBQUAD), 256, fp);
    }

    //数据
    pBmpBuf = new unsigned char[lineByte * BMP_Height];
    fread(pBmpBuf, 1, lineByte * BMP_Height, fp);

    fclose(fp);
    return true;
}

bool BMP_Save(char* bmpName, unsigned char* imgBuf, int width, int height, int biBitCount, RGBQUAD* pColorTable) {
    if (!imgBuf) return false;
    //颜色表大小，以字节为单位，灰度图像颜色表为1024字节，彩色图像颜色表大小为0
    int colorTablesize = 0;

    if (biBitCount == 8) colorTablesize = 1024;
    int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;

    FILE* fp = fopen(bmpName, "wb");
    if (fp == 0) return false;

    BITMAPFILEHEADER fileHead;
    fileHead.bfType = 0x4D42;//bmp类型

    fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte * height;
    fileHead.bfReserved1 = 0;
    fileHead.bfReserved2 = 0;

    fileHead.bfOffBits = 54 + colorTablesize;

    fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);


    BITMAPINFOHEADER head;
    head.biBitCount = biBitCount;
    head.biClrImportant = 0;
    head.biClrUsed = 0;
    head.biCompression = 0;
    head.biHeight = height;
    head.biPlanes = 1;
    head.biSize = 40;
    head.biSizeImage = lineByte * height;
    head.biWidth = width;
    head.biXPelsPerMeter = 0;
    head.biYPelsPerMeter = 0;

    fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);

    if (biBitCount == 8) fwrite(pColorTable, sizeof(RGBQUAD), 256, fp);

    fwrite(imgBuf, height * lineByte, 1, fp);

    fclose(fp);
    return true;

}

void solve(ll res = 0) {
    char Read_Path[] = BMPNAME_FOR_READ;
    BMP_Read(Read_Path);
    // 输出整体图像信息

    cout << "BMP_Width = " << BMP_Width << endl << "BMP_Height = " << BMP_Height << endl << "biBitCount = " << biBitCount << endl;

    int linebyte1 = (BMP_Width * biBitCount / 8 + 3) / 4 * 4;

    if (biBitCount == 24) {
        for (int i = 0; i < BMP_Height; ++i) {
            for (int j = 0; j < BMP_Width; ++j) {
                ++res;
            }
        }
        cout << "总的像素个素为:" << res << endl;
        cout << "----------------------------------------------------" << endl;
    }

    char writePath[] = BMPNAME_FOR_SAVE;
    BMP_Save(writePath, pBmpBuf, BMP_Width, BMP_Height, biBitCount, pColorTable);

    delete[]pBmpBuf;
    if (biBitCount == 8)
        delete[]pColorTable;
}

int main() {
    solve();
    return 0;
}
