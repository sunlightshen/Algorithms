/*
	数值概率算法 
*/
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//实际上是一种近似的方法求解积分的值 
double Darts(int n)
{
	double x,y;
	time_t t;
	int i,count=0;
	srand((unsigned)time(&t));//按时间设置值可以保证每次随机产生的值都是不相同的 
	for(i=0;i<n;i++)
	{
		x=rand()%100/100.0;
		y=rand()%100/100.0;
		if(y<=1-pow(x,2))
		{
			count++;
		}
	}
	return (double)count/(double)n;
	//int类型的函数即使返回值设置为double也会被强制转化为int类型的变量 
	
 } 
int main()
{
	int n;
	cout<<"请输入随机试验的精度："<<endl;
	cin>>n;
	double sum;
	sum=Darts(n);
	cout<<"积分值为："<<sum<<endl;
	
 } 
