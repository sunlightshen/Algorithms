#include<iostream>
using namespace std;

template<class T>
class Animals{
    public:
    void Jiao()
    {
        cout<<mAge<<"岁的动物叫"<<endl;
    }
    public:
    T mAge;
};
//为新的类模板指定类型
template<class T>
class Cat:public Animals<T>{

};
int main()
{
    Cat<int> cat;
    cat.mAge=100;
    cat.Jiao();
    

}
