
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
#define MaxChild 10

typedef int dataType;
typedef char ElemType;


typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild ,*rchild;	
} BiTNode,*BiTree; 


void visit(char c,int level){
	if(c=='D') 
		printf("%c是在二叉树的第%d层\n",c,level);

}

 void PreOrderTraverse(BiTree T,int level){
	if(T){
		visit(T->data,level);
		PreOrderTraverse(T->lchild,level+1);
		PreOrderTraverse(T->rchild,level+1); 
		
	}
} 

void InOrderTraverse(BiTree T){
	if(T){
		InOrderTraverse(T->lchild);
//		visit(T);
		InOrderTraverse(T->rchild);
	}
}


void PosOrderTraverse(BiTree T){
	if(T){
		PosOrderTraverse(T->lchild);
		PosOrderTraverse(T->rchild);
//		visit(T);
	}
}

void CreatBiTree(BiTree *T){
	char c;
	scanf("%c",&c);
	if(c==' ') *T=NULL; 
	else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));		
	}
} 

void print(BiTNode *T){
	printf("%c ",T->data);
	print(T->lchild);
	print(T->rchild);
} 
 

int main(){
	
	int level=1;
	BiTree T = NULL;
	CreatBiTree(&T);
	PreOrderTraverse(T,level);

}

 
