#include<iostream>
using namespace std;

 template<class T>
 class  Person{
public:
    Person()
    {
        mAge=0;
    }
public:
    T mAge;
 };
 //显示指定参数类型
 class SubPerson: public Person<int>{

 };