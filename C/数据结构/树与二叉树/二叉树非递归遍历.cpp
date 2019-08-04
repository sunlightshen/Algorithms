/*
        二叉树的非递归遍历
        利用栈的思想

*/
#include<iostream>
#include<cstdlib>

#define MyTrue 1
#define MyFalse 0
using namespace std;
//创建链式栈节点
typedef struct LINKNODE{
    struct LINKNODE *next;

}LinkNode;
//创建链式栈
typedef struct LINKSTACK{
    LinkNode head;
    int size;
}LinkStack;
//设置链栈的操作函数
//初始化函数
LinkStack *Init_LinkStack(){
    //开辟内存
    LinkStack *stack=(LinkStack *)malloc(sizeof(LinkStack));
    stack->head.next=NULL;
    stack->size=0;
    return stack;
}
//进栈函数
void Push_LinkStack(LinkStack *stack,LinkNode *data){
    if(stack==NULL)
        return;
    if(data==NULL)
        return;
    data->next=stack->head.next;
    stack->head.next=data;
    stack->size++;
}
//出栈函数
void Pop_LinkStack(LinkStack *stack){
    if(stack==NULL)
        return;
    if(stack->size==0)
        return;
    LinkNode *pNext=stack->head.next;
    stack->head.next=pNext->next;
    stack->size--;
}
//返回栈顶元素
LinkNode *Top_LinkStack(LinkStack *stack){
    if(stack==NULL)
        return 0;
    if(stack->size==0)
        return 0;
    return stack->head.next;
}
//返回栈元素个数
int Size_LinkStack(LinkStack *stack){
    return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack){
    if(stack==NULL)
        return;
    stack->head.next=NULL;
    stack->size=0;
}
//销毁栈
void FreeSpace_LinkStack(LinkStack * stack){
    if(stack==NULL)
        return;
    free(stack);
}
/*定义二叉树*/
typedef struct BINARYNODE{
    char c;
    struct BINARYNODE *lchild;
    struct BINARYNODE *rchild;
}BinaryNode;
/*建栈中的节点(以企业链表形式创建)*/
typedef struct BITREESTACKNODE{
        LinkNode node;
        BinaryNode *root;
        int flag;
}BiTreeStackNode;

//创建栈中的节点
BiTreeStackNode *CreateBiTreeStackNode(BinaryNode *node ,int flag){
        BiTreeStackNode *newnode=(BiTreeStackNode*)malloc(sizeof(BiTreeStackNode));
        newnode->root=node;
        newnode->flag=flag;
        return newnode;
}

//实现非递归算法
void NonRecursion(BinaryNode *root)
{
        //创建栈
        LinkStack *stack=Init_LinkStack();
        //把二叉树的节点扔到栈里
        Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(root,MyFalse));
        while (Size_LinkStack(stack)>0)
        {
                /* code */
                //先弹出栈顶元素
                BiTreeStackNode *node=(BiTreeStackNode*)Top_LinkStack(stack);
                Pop_LinkStack(stack);
                if(node->root==NULL)
                        continue;
                if(node->flag==MyTrue)
                {
                        //对树的节点进行输出
                        cout<<node->root->c<<endl;
                }
                else
                {
                        //分别把左右子树压入栈
                        Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->rchild,MyFalse));
                        Push_LinkStack(stack,(LinkNode*)CreateBiTreeStackNode(node->root->lchild,MyFalse));
                        //更改当前节点的标志位，并将其压入栈中
                        node->flag=MyTrue;
                        Push_LinkStack(stack,(LinkNode*)node);
                }
                

        }
        
}
//递归中序遍历
void Recursion(BinaryNode *root)
{
    if(root==NULL)
        return;
    cout<<root->c<<endl;
    //先访问左节点
    Recursion(root->lchild);
    //在访问右节点
    Recursion(root->rchild);
}
//创建二叉树
void CreatBinaryNode(){
    //先创建八个节点
    BinaryNode node1={'A',NULL,NULL};
    BinaryNode node2={'B',NULL,NULL};
    BinaryNode node3={'C',NULL,NULL};
    BinaryNode node4={'D',NULL,NULL};
    BinaryNode node5={'E',NULL,NULL};
    BinaryNode node6={'F',NULL,NULL};
    BinaryNode node7={'G',NULL,NULL};
    BinaryNode node8={'H',NULL,NULL};
    //建立节点关系(注意指向的是地址)
    node1.lchild=&node2;
    node1.rchild=&node6;
    node2.rchild=&node3;
    node3.lchild=&node4;
    node3.rchild=&node5;
    node6.rchild=&node7;
    node7.lchild=&node8;
    //二叉树的非递归遍历
    NonRecursion(&node1);
    cout<<"递归实现遍历----------"<<endl;
    Recursion(&node1);
    
}


int main()
{
        //创建二叉树并仅从打印
        CreatBinaryNode();
        cout<<"输出成功！"<<endl;

}
