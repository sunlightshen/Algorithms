/*
	图的遍历
	图的深度优先搜索 
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int VertexType;//定点中的数据类型 
typedef int infoType;

/*定义20个定点*/ 
#define MAX_VERTEX_NUM 20 
/*利用邻接表的方式创建图*/
int visited[5]={0,0,0,0,0};//长度为3的标记数组 
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
	int e;
	ArcNode *p,*q;
	printf("输入节点的数据信息!\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&G[i].data);//这个函数需要自己额外额创建； 
		G[i].firstarc=NULL;//先将节点的指向设为空指针； 
	}
	/*开始输入邻接矩阵*/  
	/*创建节点的连接关系*/
	for(int i=0;i<n;i++){
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
		return ((G[v].firstarc)->adjvex);
	return -1;
	//FistAdj可能出现的返回函数 
	 
} 

/*定义NextAdj函数*/
int NextAdj(VNode G[],int v){
	ArcNode *p;
    p = G[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex]) p=p->next;
		else return p->adjvex;
	}  
	return -1;//当访问到不存在邻接节点时，则结束访问 
} 
/*
	图的深度优先搜索过程
	该方法只适合于连通图  
	采用递归的思想进行访问 
*/
void DFS(VNode G[],int v){
	int w;
	printf("%d ",G[v].data);
	visited[v]=1;
	w=FirstAdj(G,v);
	while(w!=-1){
		if(visited[w]==0)
			DFS(G,w);
		w=NextAdj(G,v);
	}
} 

/*
	进行深度优先搜索的主算法 
	该方法不仅适用于连通图对于非连通图依然适用 
	随着访问节点的移动会遍历联通或者是不联通的的所有的图 
*/ 

void Travel_DFS(VNode G[],int visited[],int n){
	//初始化访问标记矩阵 
	for(int i=0;i<n;i++){
		visited[i]=0;
	} 
	//循环递归的方式开始访问图
	for(int i=0;i<n;i++){
		if(visited[i]==0)
			DFS(G,i);
	} 
	//从第一个标记为0的节点开始访问，只访问标记为0 的 节点； 
} 

int main(){
	VNode G[5];
	CreatGraph(5,G);
	Travel_DFS(G,visited,5);
	printf("节点访问情况\n");
	for(int i=0;i<5;i++){
		printf("%d ",visited[i]);
	} 
	getche();
} 
