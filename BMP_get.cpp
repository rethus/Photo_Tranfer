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
int biBitCount;//����λ��
RGBQUAD* pColorTable;//��ɫ��ָ��

bool BMP_Read(char* BMP_Name) {
    FILE* fp = fopen(BMP_Name, "rb");//��
    if (fp == NULL) return false;//��ʧ��

    fseek(fp, sizeof(BITMAPFILEHEADER), 0);//ȷ��ָ���Ƶ��ʼ

    BITMAPINFOHEADER head;
    fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
    BMP_Width = head.biWidth;
    BMP_Height = head.biHeight;
    biBitCount = head.biBitCount;

    int lineByte = (BMP_Width * biBitCount / 8 + 3) / 4 * 4;//4�ı���

    //��ɫ
    if (biBitCount == 8) {
        pColorTable = new RGBQUAD[256];
        fread(pColorTable, sizeof(RGBQUAD), 256, fp);
    }

    //����
    pBmpBuf = new unsigned char[lineByte * BMP_Height];
    fread(pBmpBuf, 1, lineByte * BMP_Height, fp);

    fclose(fp);
    return true;
}

bool BMP_Save(char* bmpName, unsigned char* imgBuf, int width, int height, int biBitCount, RGBQUAD* pColorTable) {
    if (!imgBuf) return false;
    //��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024�ֽڣ���ɫͼ����ɫ���СΪ0
    int colorTablesize = 0;

    if (biBitCount == 8) colorTablesize = 1024;
    int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;

    FILE* fp = fopen(bmpName, "wb");
    if (fp == 0) return false;

    BITMAPFILEHEADER fileHead;
    fileHead.bfType = 0x4D42;//bmp����

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
    // �������ͼ����Ϣ

    cout << "BMP_Width = " << BMP_Width << endl << "BMP_Height = " << BMP_Height << endl << "biBitCount = " << biBitCount << endl;

    int linebyte1 = (BMP_Width * biBitCount / 8 + 3) / 4 * 4;

    if (biBitCount == 24) {
        for (int i = 0; i < BMP_Height; ++i) {
            for (int j = 0; j < BMP_Width; ++j) {
                ++res;
            }
        }
        cout << "�ܵ����ظ���Ϊ:" << res << endl;
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
