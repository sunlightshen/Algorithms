/*
	动态顺序表 
*/
#include<stdio.h>
#include<conio.h> 
#include<stdlib.h> 
#define MaxSize 10
typedef int ElemType;
//定义一个数组 
typedef struct{
	int *elem;
	int length;
	int listsize;
} Sqlist;

/*数组的初始化*/
void initSqlist(Sqlist *L)//建立一个Sqlist类型的指针 
{
	L->elem=(int *)malloc(MaxSize*sizeof(ElemType));
	if(!L->elem) exit(0);
	L->length=0;
	L->listsize=MaxSize;
} 
//向列表中插入元素
void insertSqlist(Sqlist *L,int i,ElemType item)
{
	ElemType *base ,* insertPtr ,*p;
	if(i<1||i>L->length+1)
		exit(0);
	if(L->length>=L->listsize)
	{
		//内存不够用时扩展内存
		base=(ElemType*)realloc(L->elem,(L->listsize+10)*sizeof(ElemType));
		L->elem=base;
		L->listsize=L->listsize+100;
	}
	insertPtr=&(L->elem[i-1]);
	for(p=&(L->elem[L->length-1]);p>=insertPtr;p--)
	{
		*(p+1)=*p;
	}
	* insertPtr=item;
	L->length++; 
 } 
 
 /*从列表中删除数据*/
 void DelElem(Sqlist *L,int i) 
 {
 	ElemType *delItem,*q;
 	if(i<1||i>L->length)
 		exit(0);
 	delItem=&(L->elem[i-1]);
 	q=L->elem+L->length-1;//l->elem表示的是基址，加上后面的表示最后一个元素
 	for(++delItem;delItem<=q;++ delItem)
	 	*(delItem-1)=* delItem;
	L->length--;
 }
 
 //主函数 
 int main()
 {
 	Sqlist l;
 	int i;
 	initSqlist(&l);
 	for(i=0;i<15;i++)
 		insertSqlist(&l,i+1,i+1);
	//将列表中的数据打印出来
	printf("\n列表中的元素为\n");
	for(int i=0;i<l.length;i++);
		printf("%d ",l.elem[i]); 
	//删除第五个元素
	DelElem(&l,5);
	printf("\n删除后的元素为\n");
	for(int i=0;i<l.length;i++)
		printf("%d ",l.elem[i]); 
}
