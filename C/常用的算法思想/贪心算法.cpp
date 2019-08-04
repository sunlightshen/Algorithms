/*
	贪心算法
	货船的最大装箱问题 
	
*/ 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm> 
using namespace std;


//冒泡排序的的实现 
sort(int w[],int t[],int n){
	int i,j,tmp;
	int *w_tmp=(int *)malloc(sizeof(int)*n);//为数组开辟内存空间 
	for(i=0;i<n;i++){
		t[i]=i; 
	} 
	for(i=0;i<n;i++){
		w_tmp[i]=w[i];
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{	//利用冒泡排序对下表进行排序，同时下标也按照相应的顺序排列 
			if(w_tmp[j>w_tmp[j+1]])
			{
				tmp=w_tmp[j];
				w_tmp[j]=w_tmp[j+1];
				w_tmp[j+1]=tmp;
				tmp=t[j];
				t[j]=t[j+1];
				t[j+1]=tmp;
			}
		 } 
	
}

Loading(int x[],int w[],int c,int n){
	int i,s=0;
	int *t = (int *)malloc(sizeof(int)*n);
	sort(w,t,n);
	for(int i=0;i<n;i++){
		x[i]=0;
	}
	for(i=0;i<n && w[t[i]]<=c;i++){
		x[t[i]]=1;
		c=c-w[t[i]];
	}
} 
int main(){
	int x[5] ,w[5],c,i;
	cout<<"请输入货船的最大质量："<<endl;
	cin>>c;
	cout<<"请输入每个集装箱的质量："<<endl;
	for(int i=0;i<5;i++)
		cin>>w[i];
	Loading(x,w,c,5);
	cout<<"下面几个箱子将会装载到船上"<<endl;
	for(int i=0;i<5;i++){
		if(x[i]==1)
			cout<<i<<" "<<w[i]<<endl;
	} 
	return 0;
	
}

