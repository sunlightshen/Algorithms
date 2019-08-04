#include<iostream>
using namespace std;

template <class T>
class Person{
public:
    Person(T id, T age)
    {
        this->mAge=age;
        this->mId=id;
    }
    void Show()
    {
        cout<<"ID:"<<mId<<" "<<"Age:"<<mAge<<endl;
    }
public:
    T mId;
    T mAge;
};
void test01(){
    //函数模板匹配时，可以自动推到类型
    //类模板必须显示指定类型
    Person<int> p(10,20);
    p.Show();
}
int main()
{
    test01();

}