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

const int N = 3e3 + 10;

int n;
double x;
int width, height;
int vis[N];

void f() {
    int h[N];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            vis[h[i * height + j]] ++;
        }
    }
}

void solve() {

}

int main() {
    solve();
    return 0;
}
