#include<iostream>
using namespace std;
void test()
{
    //c++里将常量转化为符号表，在使用时按照符号表里的对应的值进行使用
    /*
        符号表里对应的变量是没有地址的
        对常量取地址会临时创建空间，并且为空间创建对应的指针
    */
    const int a=10;
    int *p=(int*)&a;
    *p=20;
    int array[a]={0};
    //这里的a的值并未发生变化，是真正意义上的常量
    cout<<"a="<<a<<endl;
    cout<<"输出数组a的值："<<endl;
    for(int i=0;i<a;i++)
    {
        cout<<array[i]<<endl;
    }
}
enum season{
    SPR=0,
    SUM,
    AUT,
    WIN
};
void test1()
{
    enum season s=SPR;
    if(s==SPR)
    {
        cout<<"春天"<<endl;
    }
}
typedef struct student{
    char name[100];
    int id;
}student_t;

void printS(struct student s)
{
    cout<<s.name<<"  "<<s.id<<endl;
}
//指针的引用方式
void printS1(struct student *sp)
{
    cout<<sp->id<<"  "<<sp->name<<endl;
}
//正常引用的方式进行的
void printS2(struct student &s)
{
    cout<<s.name<<"   "<<s.id<<endl;
}
//常量指针的引用
void motify(int *const a)
{
    *a=30;
}
//正常变量的引用
void motify1(int &a)
{
    a=300;
}
// 引用可以作为函数的返回值
int main()
{
    student s1={"shenguang",10};
    printS(s1);
    cout<<endl;
    //注意这里给的是地址，这样方便与指针的引用
    printS1(&s1);
    cout<<endl;
    printS2(s1);
    int a;
    motify(&a);
    cout<<"a="<<a<<endl;
    cout<<"----------"<<endl;
    motify1(a);
    cout<<"a="<<a<<endl;
}