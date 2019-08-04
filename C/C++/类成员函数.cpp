#include<iostream>
using namespace std;
class Box
{
    public:
        double length;
        double width;
        double high;
        double volume()
        {
            return length*width*high;
        }
        double getVolume(void);
};
//外部域的定义，需要在类的内部进行声明，sheng
double Box::getVolume(void)
{
    return length*width*high;
}
int main()
{
    Box box1={10.0,10.0,10.0};
    double vol1=box1.volume();
    double vol2=box1.getVolume();
    cout<<"箱子1的体积为："<<vol1<<endl;
    cout<<"箱子2的体积为："<<vol2<<endl;
} 
