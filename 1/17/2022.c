#include<stdio.h>
int Swap(int* a, int* b)//交换两个整数，练习函数调用，使用指针
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
    return 0;
}
int main(){
    int a,b;
    printf("请输入两个整数");
    scanf("%d %d",&a,&b);
    Swap(&a,&b);
    printf("%d \t %d",a,b);
    return 0;
}