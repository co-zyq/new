#include<stdio.h>
#include<math.h>
//面积公式
double S(double a,double b, double c){
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
//判断能否构成三角形
int check(double a, double b, double c){
  // 先判断正数
    if (a <= 0 || b <= 0 || c <= 0){
        printf("边长必须为正数,不能为0或负数\n");
        return 0;
    }
    // 再判断三角不等式
    if (a + b > c && a + c > b && b + c > a){
        printf("输入的三边可以构成三角形\n");
        return 1;
    }
    printf("输入的三边不能构成三角形\n");
    return 0;
}

int main(){
    double a,b,c;
    int r = scanf("%lf %lf %lf",&a,&b,&c);
//利用海伦公式确保输入的是三个数字 
    if(r != 3){
        printf("输入错误必须输入3个数字\n");
        while(getchar()!='\n'); 
    }
//检查是否能构成三角形
    if (check(a, b, c)) {
        printf("三角形面积为：%.2lf\n", S(a, b, c));
    }
}