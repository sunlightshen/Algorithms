/*
    本历程实现二叉树的创建
    二叉树的#创建方法
*/
#include<iostream>
using namespace std;

//定义二叉树的节点
typedef struct BINARYNODE{
    char c;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
}BinaryNode;

//递归遍历
void Recursion(BinaryNode *root){
    if(root==NULL)
        return;
    //打印中间节点数据
    cout<<root->c<<endl;
    Recursion(root->lchild);
    Recursion(root->rchild);

}
//创建二叉树
BinaryNode *CreateBinaryTree()
{
    char c;
    cin>>c;
    BinaryNode *node;
    BinaryNode *lchild;
    BinaryNode *rchild;
    if(c=='#')
    {
        node=NULL;
    }
    else
    {
        node=(BinaryNode *)malloc(sizeof(BinaryNode));
        node->lchild=CreateBinaryTree();
        node->rchild=CreateBinaryTree();
    }
    return node;
    
}
int main()
{
    //创建二叉树
    BinaryNode *root=CreateBinaryTree();

}