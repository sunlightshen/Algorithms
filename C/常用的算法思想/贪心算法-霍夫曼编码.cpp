/*
	贪心算法-霍夫曼编码 
	主要思想：每次寻找局部最优解 
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//定义全局变量：
int count=0; 
zhaoling(double recv,double srecv ,int juzhen[])
{

	double give=recv-srecv;
	double money[3]={1.0,0.5,0.1};
	int l;
	for(int i=0;i<3;i++)
	{
		l=0;
		while(1)
		{
			l++;
			if(give-(double)l*money[i]<=0)
				break;
		}
		juzhen[i]=l-1;
		give=give+money[i];
	}
	return count;
}
int main()
{
	double sum1=2.7;
	double sum2=3.0;
	int juzhen[3]={0};
	int count=0;
	count=zhaoling(sum2,sum1,juzhen);
	for(int i=0;i<3;i++)
	{
		cout<<juzhen[i]<<" ";
	}
	cout<<endl;
	cout<<"最小找零钱数为："<<count<<endl; 
	 
 	
}
