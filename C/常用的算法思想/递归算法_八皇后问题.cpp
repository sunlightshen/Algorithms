/*
	递归算法-----实现八皇后问题 
*/ 
#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int count=0;//定义全局变量进行方法数的记录 

int isCorrect(int i,int j,int (*Q)[8])
{
	int s,t;
	//本函数与目的用于判断（i,j）位置上上能否放回皇后
	/*同时判断该位置的前、后、左、右、右上、右下、左上、左下*/ 
	for(s=0,t=j;s<8;s++)//前后 
		if(Q[s][t]==1) return 0;
	
//	for(s=i,t=0;t<8;t++)//前后 
//		if(Q[s][t]==1 && t!=j) return 0;
//	
	for(s=i,t=j;s>=0&&t>=0;s--,t--)//左上 
		if(Q[s][t]==1) return 0;
		
	for(s=i,t=j;s<8&&t<8;s++,t++)//左下 
		if(Q[s][t]==1) return 0;
		
	for(s=i,t=j;s<8&&t>=0;s++,t--)//右上 
		if(Q[s][t]==1) return 0;
		
	for(s=i,t=j;s>=0&&t<8;s--,t++)//右下 
		if(Q[s][t]==1) return 0;
	return 1;
	//当以上情况都不存在时则说明该位置上是可以防止皇后的 	
}

void Queen(int row,int (*Q)[8])
{
	int i,j;
	int Q2[8][8];
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
		Q2[i][j]=Q[i][j]; 
	if(row==8)//递归到8时说明地柜完成打印输出此时的皇后的棋盘分布 
	{
		cout<<"满足条件的排列:"<<endl; 
		count++;//没完成一轮进行一次自加运算 
		for(int i=0;i<8;i++)
		{ 
			for(int k=0;k<8;k++)
			{
				cout<<Q2[i][k]<<" ";//循环输出i行k列的数据 
		 	} 
		 	cout<<endl;//每行输入完成进行换行输出 
		} 
	}
	else{
	
	for(int j=0;j<8;j++)
	{
		if(isCorrect(row,j,Q2))//在判断完成后可以进行防止 
		{
			for(int i=0;i<8;i++)
				Q2[row][i]=0;//先把这一行的全部设置为0 
			Q2[row][j]=1;//再讲该位置设置为1 
			Queen(row+1,Q2);
		}
	}
}
}
int main(){
	int Q[8][8];
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
		Q[i][j]=0;
	Queen(0,Q);
	cout<<"皇后分布总个数为："<<count<<endl; 
}
