/*
	功能：递归的思想实现整数的划分 
*/
#include<stdlib.h>
#include<stdio.h> 
//建立整数划分的递归函数 
int P(int n,int m){
	if(m==1) return 1;
	if(n<m)  return P(n,n);
	if(n==m) return 1+P(n,n-1);
	return (P(n,m-1)+P(n-m,m));
}
int main()
{
	int n;
	printf("请输入n：\n");
	scanf("%d",&n);
	int sum=P(n,n);
	printf("总的划分数目为：%d",sum); 
}
