/*
	ѭ���������֪ʶ 
*/ 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXQSIZE 100

typedef char ElemType;

/*����ѭ������*/
typedef struct{
	ElemType *base;
	int front;
	int rear; 
}cycleQueue;

/*��ʼ��ѭ������*/
void initQueue(cycleQueue *q){
	q->base = (ElemType *)malloc(MAXQSIZE*sizeof(ElemType));//Ϊ�俪���������ڴ� 
	if(!q->base) exit(0);
	q->front=q->rear=0;//��ͷָ���βָ��ָ��0λ�� 
	printf("\nѭ�����г�ʼ�����!\n"); 
} 

/*�����*/
void EnQueue(cycleQueue *q ,ElemType e){
	if((q->rear+1)%MAXQSIZE==q->front) exit(0);//ѭ����������
	q->base[q->rear]=e;
	q->rear=(q->rear+1)%MAXQSIZE; 
	if((q->rear)%MAXQSIZE+1==(q->front)%MAXQSIZE)
		printf("ѭ������������\n");
} 

/*�����в���*/
void DeQueue(cycleQueue *q,ElemType *e) {
	if(q->front==q->rear) exit(0);
	*e=q->base[q->front];
	q->front=(q->front+1)%MAXQSIZE;
}

void print(cycleQueue *q){
	ElemType e;
	if(q->front==q->rear)
		printf("\n����һ���ն���!\n");
	while(q->front!=q->rear){
		e=q->base[q->front];//����д����Ϊѭ���������ٵ��ڴ�ռ��������� 
		q->front=(q->front+1)%MAXQSIZE;
		printf("%c ",e);
	}
} 

/*����������һ��ѭ�������У���ʵ�ֶ��������ݵĴ�ӡ���*/
int main()
{
	
	cycleQueue s;
	ElemType c;
	initQueue(&s);//��ս���г�ʼ��
	scanf("%c",&c);
	/*ִ������в���*/
	while(c!='@')
	{
		EnQueue(&s,c);
		scanf("%c",&c);
	} 
	printf("\n��������!\n"); 
	/*��ӡѭ�������е�����*/
	printf("\n�����в���!\n");
	print(&s);
	
 } 
