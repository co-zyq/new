#include <iostream>
using namespace std;

void swap_by_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    swap_by_ref(x, y); // 直接传递变量，无需取地址
    cout << "x=" << x << ", y=" << y << endl;
    return 0;
}