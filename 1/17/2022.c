#include<stdio.h>
#if 0
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
#endif
#if 1
int main(){
    int a,b;
    char operater;//+-*/运算符
    printf("请输入");//整数 运算符 整数
    scanf("%d %c %d",&a,&operater,&b);
    switch (operater)
    {
    case ('+'):
       return printf("%d",a+b);
        break;
    case ('-'):
       return printf("%d",a-b);
        break;
    case ('*'):
        return printf("%d",a*b);
        break;
    case ('/'):
       return printf("%d",a/b);
        break;
    default:
       return printf("输入的运算符不属于加减乘除");
        break;
    }
}
#endif