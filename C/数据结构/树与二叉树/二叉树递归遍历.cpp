/*
    本历程实现二叉树的创建
    二叉树的#创建方法
*/
#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

//定义二叉树的节点
typedef struct BINARYNODE{
    char c;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
}BinaryNode;

//递归遍历
void Recurision(BinaryNode *root)
{
    if(root==NULL )
        return;
    //先访问根节点在访问左子树
    printf("%c",root->c);
    //在遍历左子树
    Recurision(root->lchild);
    //再遍历右子树
    Recurision(root->rchild);
}
//创建二叉树
BinaryNode *CreateBinaryTree()
{
	fflush(stdin);
	
    char c;
    BinaryNode *node;
    scanf("%c",&c);
 
	if(c=='#')
	{
		node=NULL;
	}
	else
	{
		node=(BinaryNode *)malloc(sizeof(BinaryNode));
		node->c=c;
		node->lchild=CreateBinaryTree();
		node->rchild=CreateBinaryTree();
	}
	return node;
     
}
int main()
{
    //创建二叉树
    BinaryNode *root=CreateBinaryTree();
    cout<<"创建完成！"<<endl;
	Recurision(root);            

}
