/*
	队列 
	这里用链表实现一个队列 
	队列实现先进先出的基本规则 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char QelemType; 
typedef struct QNode{
	QelemType data;
	struct QNode *next;
	
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


//创建一个队列
void initQueue(LinkQueue *q){
	//初始化一个空队列
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!q->front) exit(0);//创建头结点失败
	q->front->next =NULL;  
	printf("初始化成功\n");
} 
//入队列 
void EnQueue(LinkQueue *q,QelemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(p==NULL) exit(0);
	p->data=e;
	p->next=NULL;
	q->rear->next = p;
	q->rear = p; 
 } 
//出队列
void DeQueue(LinkQueue *q,QelemType *e){
 	//如果队列q不为空则删除队头元素，用e返回其对应的值
 	QueuePtr p;
	 if(q->front == q->rear) exit(0);
	 p=q->front->next;
	 *e = p->data;
	 q->front->next=p->next;
	 if(q->rear == p) q->rear = q->front;
	 free(p); 
 } 
//销毁队列
void DestroyQueue(LinkQueue *q){
	while(q->front){
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
		
	}
} 
//输出队列数据

void print(LinkQueue * q)
{
  QNode * p = q->front->next;
 
  if (q->front==q->rear) {
    printf("空队\n");
  }
  while (p) {
    printf("%c ", p->data);
    p = p->next;
  }
  printf("\n\n");
}
/*创建一个队列实现队列数据的入队和出队操作，并将变化后的队列打印出来*/
int main()
{
	QelemType c;
	LinkQueue s;
	initQueue(&s);
	scanf("%c",&c);
	while(c!='#'){
		EnQueue(&s,c);
		scanf("%c",&c);	
	}
	printf("输入数据完成\n"); 
	print(&s); //输出队列中的数据	
	DestroyQueue(&s); 
	printf("\n毁掉对而后重新打印数据:\n"); 
//	print(&s);因为此时内存里不存在数据，所以在输出时会出现错误 
 } 
 
