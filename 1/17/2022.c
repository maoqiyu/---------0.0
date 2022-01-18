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
#if 0
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

/*练习struct ，做一个学生成绩表，包含名字，年龄，成绩，使用动态分配内存*/
#if 1
struct student//存储名字，年龄，分数
{
    char name[10];
    int  age;
    float scores;
};
void input(struct student *p){
    printf("请输入名字 年龄 分数\n");
    scanf("%s",p->name);
    scanf("%d",&(p->age));
    scanf("%f",&(p->scores));
}
void main(){
    struct student *stu;
    struct student *p=0,*q=0;
    int cap,n=0;
    printf("请出入成绩表容量大小");
    scanf("%d",&cap);
    stu=(struct student *)malloc(cap*sizeof(struct student));
    if(!stu)
    return printf("内存分配失败！");
    p=stu;
    while(1){
        if(n>cap){
            printf("扩大2倍内存！");
            stu=(struct student*)realloc(stu,2*cap*sizeof(struct student));
            if(!stu)
            return printf("扩大内存分配失败！");
        }
        input(p);
        if(p->scores<0)
        break;
        p++;
        n++;
    }
    q=p;
    for(p=stu;p<q;p++){
        printf("%s %d %f",p->name,p->age,p->scores);
    }

}
#endif