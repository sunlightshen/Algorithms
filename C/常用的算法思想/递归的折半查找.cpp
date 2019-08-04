/*
	功能：递归的折半查找算法啊 
*/  
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//定义递归折半查找函数 
int bin_search(int key[],int low,int high,int k){
	int mid;
	if(low>high) return-1;
	else{
		mid=(low+high)/2;
		if(key[mid]==k)
			return mid;
		if(k>key[mid])
			return bin_search(key,mid+1,high,k);
		else
			return bin_search(key,low,mid-1,k); 
	}
}
int main(){
	int n,i,addr;
	int A[10]={2,3,5,7,8,10,12,15,19,21};
	printf("需要查找的数组为：\n");
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	} 
	printf("\n");
	printf("请输入您要查找的数：\n");
	scanf("%d",&n);
	addr=bin_search(A,0,9,n);
	if(addr!=-1){
		cout<<n<<"是第"<<addr+1<<"个元素！"<<endl;
	}
	else
		cout<<"数组中不存在"<<n<<"!"<<endl;
} 
