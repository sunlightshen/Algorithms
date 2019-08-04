/*
	折半查找 
	折半查找只适合于按固定大小顺序排列的一组数据的查找 
*/
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

typedef int keytype;

//折半查找方法的实现 
int bin_search(keytype key[],int n,keytype k){
	int low=0,high=n-1,mid;
	while(low<high){
		mid=(low+high)/2;
		if(key[mid]==k)
			return mid;
		if(key[mid]<k)
			low=mid+1;
		else
			high=mid-1; 
	}
	return -1;
} 
int main(){
	
	keytype a[10]={1,2,3,4,5,6,7,8,9,10};
	int addr;
	addr = bin_search(a,10,8);
	printf("查找到的数的位置为%d\n",addr);
	printf("查找到的数字为%d\n",a[addr]); 
	
} 
