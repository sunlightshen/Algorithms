/*
	贪心算法最小找零钱的问题 
*/ 
#include<stdio.h>
#include<iostream>
#include<algorithm> 
using namespace std;

zhaoling(float sum,float recv,int v[])
{
	float tmp,l;
	float num;
	int j;
	num=recv-sum; 
	//sum是应收金额，recv是实收的钱，v找出的各个币种的个数的数组
	float money[3]={1.0,0.5,0.1};//所有可找出的币种
	for(int i=0;i<3;i++){
		l=0;
		for(j=0;j<=5;j++)
		{
			if((num-money[i]*j)<=0)
				break;
		}
		v[i]=j-1;
		num=num-v[i]*money[i];
	} 
}

int main()
{
	float m,n;
	int v[3];
	cout<<"请输入最佳应收总金额："<<endl;
	cin>>m;
	cout<<"请输入实收总金额:"<<endl;
	cin>>n;
	zhaoling(m,n,v);
	cout<<"最佳找零方案"<<endl;
	int sum=0; 
	for(int i=0;i<3;i++)
	{
		cout<<v[i]<<" ";
		sum=sum+v[i]; 
	 } 
	 cout<<endl;
	 cout<<"最小找零数目为:"<<endl;
	 cout<<sum;
	 
	
 } 
