/*
	图的遍历
	图的广度优先搜索 
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*********队列的参数的设置***********/
typedef int QelemType; 
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
//判断队列为空函数
int emptyQ(LinkQueue *q){
	if(q->front == q->rear) 
		return 1;
	return 0;
} 

QelemType c;
LinkQueue s;

/************************************************/ 

typedef int VertexType;//定点中的数据类型 
typedef int infoType;
/*定义20个定点*/ 
#define MAX_VERTEX_NUM 20 
/*利用邻接表的方式创建图*/
int visited[10];
/*图的定义*/
typedef struct ArcNode{
	/*定义节点的类型*/
	int adjvex;
	struct ArcNode *next;//定义连接另一条边的指针
	infoType *weight; //定义相应的权重 
} ArcNode;

typedef struct VNode{
	/*定义定点的类型*/
	VertexType data;//顶点中数据的类信息 
	ArcNode *firstarc;//定义一个指向单链表的指针 
}  VNode; 

/*图的创建*/ 
/*两个参数：
			第一个为需要创建的的顶点数目
			要创建的图的存储结构，一般来说是自己创建好的结构体 
*/
/*创建图时需要提前加上其对应的邻接表的存储形式*/ 

void CreatGraph(int n,VNode G[]){
	int i,e;
	ArcNode *p,*q;
	printf("输入节点的数据信息!\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&G[i].data);//这个函数需要自己额外额创建； 
		G[i].firstarc=NULL;//先将节点的指向设为空指针； 
	}
	/*开始输入邻接矩阵*/  
	/*创建节点的连接关系*/
	for(i=0;i<n;i++){
		printf("开始为第%d个节点创建边!(结束请输入-1)\n",i);
		scanf("%d",&e);
		//输入-1时即表示创建截至 
		while(e!=-1){
			p=(ArcNode *)malloc(sizeof(ArcNode));//首先邻接的边开辟内存存储空间 
			p->next=NULL;
			p->adjvex=e;
			if(G[i].firstarc == NULL) G[i].firstarc=p;
			else q->next=p;
			q=p;
			scanf("%d",&e);
		}
	} 
	printf("图的创建完成！\n"); 
} 

/*定义visit函数*/
void visit(int v){
	printf("%d ",v);
	//visited用于获取节点数据，并将数据存储在w这个变量中 
}  

/*定义FirstAdj函数*/
int FirstAdj(VNode G[],int v){
	if(G[v].firstarc!=NULL)
		return (G[v].firstarc)->adjvex;
	return -1;
	//FistAdj可能出现的返回函数 ,这是求解第一个节点 
	 
} 

/*定义NextAdj函数*/
int NextAdj(VNode G[],int v){
	ArcNode *p;
    p = G[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex]) p=p->next;
		else return p->adjvex;
	} 
	return -1; 
} 


/*
/*图的广度优先搜索*/
void BFS(VNode G[],int v){
	int w;
	initQueue(&s);
	visit(G[v].data);//对节点的操作函数 
	visited[v]=1;
	EnQueue(&s,v);//将队列压入栈 
	while(!emptyQ(&s)){
		DeQueue(&s,&v);
		w=FirstAdj(G,v);
		while(w!=-1){
			if(visited[w]==0){
				visit(G[w].data);
				EnQueue(&s,w);
				visited[w]=1; 
			}
			w=NextAdj(G,v);
		}
	} 
}  


/*广度优先搜索主算法*/ 
void Travel_BFS(VNode G[],int visited[], int n){
	
	int i;
	//访问节点标记矩阵初始化 
	for(i=0;i<n;i++){
		visited[i]==0;
	}
	//开始对节点进行访问
	for(i=0;i<n;i++){
		if(visited[i]==0)//只对标记为0的节点进行访问 
			BFS(G,i);
	} 
} 

int main(){

	VNode G[5];
	CreatGraph(5,G);
	Travel_BFS(G,visited,5);
	/*BFS方便于连通图的遍历，而对于非连通图则需要利用主循环对
	节点一次的测试，找出未访问过的节点继续进行测试 
	*/ 
	printf("各节点的访问情况！\n");
	for(int i=0;i<5;i++){
		printf("%d ",visited[i]);
	}
} 
