/*
	回溯算法实现-四皇后问题 
	其主要思想类似于树的深度遍历 ，通过遍历所有子树来找到所有满足所有条件的解 
*/ 
#include<stdio.h> 
#include<iostream>
#include<conio.h>
using namespace std;

int count=0;
//判断该棋盘位置是否可以安放棋子
int isCorrect(int i,int j,int (*Q)[8])
{
	int n=8;
	int s,t;
	for(s=i,t=0;t<n;t++)
		if(Q[s][t]==1) return 0;
	for(s=j,t=0;t<n;t++)
		if(Q[t][s]==1) return 0;
	for(s=i+1,t=j+1;s<n,t<n;s++,t++)
		if(Q[s][t]==1)	return 0;
	for(s=i-1,t=j-1;s>=0,t>=0;s--,t--)
		if(Q[s][t]==1) return 0;
	for(s=i-1,t=j+1;s>=0,t<n;s--,t++)
		if(Q[s][t]==1) return 0;
	for(s=i+1,t=j-1;s<n,t>=0;t--,s++)
		if(Q[s][t]==1) return 0;
	return 1;	
 } 
//定义寻找皇后函数 
void Queue(int j,int (*Q)[8])
{
	int n=8;
	if(j==n)
	{
		count++;
		cout<<"满足条件的棋盘"<<endl; 
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<n;k++)
			{
				cout<<Q[i][k]<<" ";
			 } 
			cout<<endl;
		} 
		
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(isCorrect(i,j,Q))
		{
			Q[i][j]=1;
			Queue(j+1,Q);
			Q[i][j]=0;
			//在找到满足条件的解后还要进行下面的遍历，因此需要重新将该出的回复成0才可以 
		}
	}
	
 } 
int main()
{
	int n=8;
	int Q[8][8];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		Q[i][j]=0;
	Queue(0,Q);
	cout<<"满足条件的总数为："<<count<<endl; 
}
