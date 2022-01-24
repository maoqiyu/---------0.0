#include<cstdio>
#include<iostream>
using namespace std;


#if 1
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
int main(){
    first::a=1;
    second::a=1.1;
    cout<<first::a<<"  "<<second::a<<endl;
    
}
#endif

#if 0
int main(){
    
}
#endif

#if 0
int main(){
    
}
#endif
