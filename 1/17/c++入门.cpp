#include<cstdio>
#include<iostream>
using namespace std;


#if 0
//1. namespace名字空间的使用
namespace first{
    int a;
    void f(){};
    char g;
}
namespace second{
    double a;
    int f(){};
    int g(){};
}
/*namespace三种使用方法：
1. using namespace::std; /using namespace::first;
2. using std::cout; / using first::a;
3. std::cout; / first::a;
*/ 
using namespace first;
int main(){
    a=1;
    second::a=1.1;
    cout<<a<<"  "<<second::a<<endl;
    
}
#endif

#if 0
//程序块{}内部作用域可定义域外部作用域同名的变量
int main(){
    int a=1;
    cout<<a<<"  "<<&a<<endl;
    {
        int a=3;
        cout<<a<<"  "<<&a<<endl;
    }
    cout<<a<<"  "<<&a<<endl;
}
//输出结果：可以发现，地址是不一样的
//1  0x61fe18
//3  0x61fe1c
//1  0x61fe18，在{}的内外，同名变量独立。
#endif

//for语句可以定义局部同名变量
#if 1
int main(){
        int i = 1;
    cout << i << "  " << &i<<endl;
    for (; i <= 2;i++){
        cout << i << "  " << &i<<endl;
    }
    for (int i = 0; i <= 1;i++){
        cout << i << "  " << &i<<endl;
    }
    cout << i << "  " << &i<<endl;
}


/*
执行结果说明，for语句可以定义内部变量，也可以从外部使用同名变量，
1  0x61fde8
1  0x61fde8
2  0x61fde8
0  0x61fdec
1  0x61fdec
3  0x61fde8  若使用了外部变量，就会对外部变量产生影响
*/
#endif
#if 0
//访问和内部作用域变量同名的全局变量，要用全局作用域限定 ::
int a = 1;
int main(){
    int a = 2;
    {
        int a = 3;
        cout << a << "  " << &a << endl;
        cout << ::a<<"  "<< &(::a) << endl;
    }
    cout << a << "  " << &a << endl;
    cout << ::a<<"  "<< &(::a)<< endl;
}
/*输出结果：这里全局变量和namespace类似，不需要括号内容(namespace)::a;
3  0x61fe18
1  0x403010
2  0x61fe1c
1  0x403010
*/
#endif

#if 0
//C++引入了“引用类型”，即一个变量是另一个变量的别名
int main(){
    int a = 3;
    int c = 1;
    int &b = a;
    
    cout << a << "  " << b << endl;
    cout << &a << "  " << &b << endl;
    b = c;
    cout << a << "  " << b << endl;
    cout << &c << "  " << &b << endl;
}
/* 输出结果：说明a和b是同一变量的不同变量名;
3  3
0x61fe08  0x61fe08
1  1
0x61fe0c  0x61fe08
*/
#endif
//函数重载，允许使用相同的函数名，通过参数类型不同来区分使用哪一个
//不能通过返回类型来区分
//函数需要：返回类型 函数名 （形式参数可有可无）
#if 1

int cadd(int a, int b){
    return a+b;
}
double cadd(double a, double b){
    return a+b;
}
int main(){
    int a=3,b=4;
    cout<<cadd(a,b);
}

#endif

#if 1
//运算符重载是用于自己定义的数据类型，一定有struc或class
//运算符重载是重载函数的一种特殊类型，函数就包括了返回类型 函数名(确定了) (形式参数)
#include<iostream>
using namespace std;
struct Vector2
{ //{};放好分号!
    double x;
    double y;;
};
Vector2 operator * (double a,Vector2 p){//*和<<的有区别，但是目前我还不清楚在哪
    Vector2 c;
    c.x=a*p.x;
    c.y=a*p.y;
    return c;
};
 ostream& operator << (ostream& i,Vector2 p){
    cout << p.x << "  " << p.y << endl;
    return i;
};
int main(){
    Vector2 p,d;
    p.x=1.1;
    p.y=2.2;
    int a=2;
    d=a*p;
    cout<< d;
}
#endif