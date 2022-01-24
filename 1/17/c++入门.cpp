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
