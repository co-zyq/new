#include <iostream>
using namespace std;
int main() {
    int score = 85;
    int *p;         // 声明一个指向 int 的指针 p
    p = &score;     // 将 score 的地址赋给 p（& 是取地址运算符）

    cout << "score = " << score << endl;
    cout << "Address of score: " << p << endl;
    cout << "Value via pointer: " << *p << endl;

    *p = 90;        // 通过指针修改 score 的值
    cout << "After update, score = " << score << endl;

    return 0;
}