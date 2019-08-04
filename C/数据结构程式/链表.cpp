/*链表*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef int ElemType;

/*定义一个链表类型的结构体*/
typedef struct node{
	ElemType data;//数据域 
	struct node *next;//指针域 
}LNode,*LinkList;
/*创建一个链表*/

LinkList GreatLinkList(int n){
	/*建立一个长度为n的链表*/
	LinkList p,r,list=NULL;
	//list永远是链表的头指针，r永远指向链表的末尾 
	ElemType e;
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&e);
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e;
		p->next=NULL;
		if(!list)
			list=p;
		r=p;
	} 
	return list;//返回给主函数的永远头指针 
}  


/*向链表中插入元素*/
void insertList(LinkList *list,LinkList q,ElemType e){
	/*向链表中指针q指出的节点的后面插入节点，节点数据为e*/
	LinkList p;
	p=(LinkList)malloc(sizeof(LNode));
	p->data=e;
	if(!*list)
	{
		*list=p;
		p->next=NULL; 
	}else{
		p->next=q->next;
		q->next=p;
	}
} 

/*删除节点*/
void delLink(LinkList *list,LinkList q)
{
	LinkList r;
	if(q==*list)
	{
		*list=q->next;
		free(q);
	 }else{
	 	for(r=*list;r->next!=q;r=r->next);//找出q的前驱节点 
	 	if(r->next!=NULL){
	 		r->next=q->next;
	 		free(q); 
	 		//找到q并把q进行释放 
		 } 
	 }
} 
/*销毁链表*/
void destroyLinkList(LinkList *list)
{
	LinkList p,q;
	p=*list;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	*list=NULL;//防止list变为野指针 
 } 
int main() 
{
	int e,i;
	LinkList l,q;
	q=l=GreatLinkList(1);
	scanf("%d",&e);
	while(e)
	{
		insertList(&l,q,e);
		q=q->next;
		scanf("%d",&e);
	}
	q=l;
	printf("\n链表中存入的数据为\n");
	while(q){
		printf("%d ",q->data);
		q=q->next;
	} 
	 
	//删除第五个节点
	printf("\n打印删除后的结果\n"); 
	q=l;
	for(int i=0;i<4;i++)
	{
		q=q->next;
	 } 
	delLink(&l,q);
	
	//打印删除后的结果
	q=l;
	while(q){
		printf("%d ",q->data);
		q=q->next;
	} 
	//释放节点
	destroyLinkList(&l);
	getche(); 
	 
}
