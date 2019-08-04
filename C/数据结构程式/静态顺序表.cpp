/*
	静态顺序表 
*/ 
#include<stdio.h>
#define MaxSize 10
  
//向表中插入元素 
void insertElem(int Sqlist[],int *len,int i,int x) 
{
	int t;
	if(*len==MaxSize || i<1 || i>*len+1)
	{
		printf("输入非法\n");
		return;
	}
	for(t=*len-1;t>=i-1;t--)
	{
		Sqlist[t+1]=Sqlist[t];
	 } 
	 Sqlist[i-1]=x;
	 *len=*len+1;
}
//向表中删除元素
void DelElem(int Sqlist[],int *len, int i)
{
	int j;
	if(i<1||i>*len)
	{
		printf("输入非法\n");
		return; 
	}
	for(j=i;j<*len-1;j++)
	{
		Sqlist[j-1]=Sqlist[j];
	}
	*len=*len-1;
 } 
//主函数（测试函数）
int main()
{
	/*先定义一个链表*/
	int Sqlist[MaxSize];
	int len;
	int i;
	for(i=0;i<6;i++)
	{
		scanf("%d",&Sqlist[i]);
	} 
	len=6;
	/*按顺序打印顺序表中数据*/
	for(int i=0;i<len;i++)
	{
		printf("%d ",Sqlist[i]);
	 } 
	 printf("\n空格的数量为%d\n",MaxSize-len);
	insertElem(Sqlist,&len,3,0);
	printf("插入后len的长度为：\n",len);
	for(int i=0;i<len;i++)
	{
		printf("%d ",Sqlist[i]);
	 } 
	 printf("\n空格的数量为%d\n",MaxSize-len);
	 insertElem(Sqlist,&len,11,0);
	 DelElem(Sqlist,&len,6);
	 for(int i=0;i<len;i++)
	 {
	 	printf("%d ",Sqlist[i]);
	 }
	 printf("\n空格的数量为%d\n",MaxSize-len);
 } 
