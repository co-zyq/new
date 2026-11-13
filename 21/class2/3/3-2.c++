#include <iostream>
using namespace std;

void swap_by_ptr(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap_by_ptr(&x, &y); // 调用时需取地址
    cout << "x=" << x << ", y=" << y << endl;
    return 0;
}