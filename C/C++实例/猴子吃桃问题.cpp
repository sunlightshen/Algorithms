#include<iostream>
using namespace std;
int main()
{
    int x,y;
    x=1;
    for(int i=1;i<10;i++)
    {
        y=(x+1)*2;
        x=y;
    }
    cout<<y<<endl;
}