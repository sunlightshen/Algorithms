/*本身是一个链表*/
/*
    链栈一链表的形式来实现栈，但是相对于链表更加的简单
*/
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
//创建链式栈节点
typedef struct LINKNODE{
    struct LINKNODE *next;

}LinkNode;
//创建链式栈
typedef struct LINKSTACK
{
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
void Push_LinkStack(LinkStack *stack,LinkNode *data)
{
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
LinkNode *Top_LinkStack(LinkStack *stack)
{
    if(stack==NULL)
        return 0;
    if(stack->size==0)
        return 0;
    return stack->head.next;
}
//返回栈元素个数
int Size_LinkStack(LinkStack *stack)
{
    return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack)
{
    if(stack==NULL)
        return;
    stack->head.next=NULL;
    stack->size=0;
}
//销毁栈
void FreeSpace_LinkStack(LinkStack * stack)
{
    if(stack==NULL)
        return;
    free(stack);
}
typedef struct Person
{
    /* data */
    LinkNode node;
    char name[64];
    int age;
};

int main()
{
    //创建栈
    LinkStack *stack=Init_LinkStack();
    Person p1,p2,p3,p4,p5;
    strcpy(p1.name,"aaa");
    strcpy(p2.name,"bbb");
    strcpy(p3.name,"ccc");
    strcpy(p4.name,"ddd");
    strcpy(p5.name,"eee");
    p1.age=1;
    p2.age=2;
    p3.age=3;
    p4.age=4;
    p5.age=5;
    Push_LinkStack(stack,(LinkNode*)&p1);
    Push_LinkStack(stack,(LinkNode*)&p2);
    Push_LinkStack(stack,(LinkNode*)&p3);
    Push_LinkStack(stack,(LinkNode*)&p4);
    Push_LinkStack(stack,(LinkNode*)&p5);

    while(Size_LinkStack(stack)>0){
        //取出栈顶元素
        Person *p=(Person *)Top_LinkStack(stack);
        cout<<"Name:"<<p->name<<"  "<<"Age:"<<p->age<<endl;
        Pop_LinkStack(stack);
    }
    //打印完成后进行销毁
    FreeSpace_LinkStack(stack);
    //栈的陷入先进先出演示完成
}