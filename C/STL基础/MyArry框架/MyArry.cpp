#include<iostream>
using namespace std;

template<class T>
class MyArry{
    public:
        MyArry(int capacity);
        MyArry(const MyArry &arr);
        T &operator[](int dex);
        MyArry<T> operate=(const MyArry<T>&arr);
    

    public:
        //可容纳元素总数
        int mCapacity;
        //当前数组元素                                                                                
        int mSize;
        //保存数据首地址
        T *pAddr;

};
int main()
{

}