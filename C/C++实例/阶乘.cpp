#include<iostream>
using namespace std;
int jiecheng(int n)
{
    if(n==1)
        return 1;
    else
    {
        
        return n*jiecheng(n-1);
    }
    
}
int main()
{
    int num=1;
    int n=10;
    for(int i=1;i<=n;i++)
    {
        num=i*num;
    }
    cout<<"循环输出"<<num<<endl;
    int count=jiecheng(10);
    cout<<"递归输出"<<count<<endl;
}