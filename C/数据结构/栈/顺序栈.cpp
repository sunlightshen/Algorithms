#include<iostream>
#include<cstdlib>
using namespace std;
#define MAX_SIZE 100

//创建数据
typedef struct PERSON
{
    /* data */
    char name[20];
    int age;
}Person;

typedef struct SEQSTACK
{
    void *data[MAX_SIZE];
    int size;
}SeqStack;


/*栈的操作*/
//栈的初始化
SeqStack *Init_SeqStack(){
    //开辟内存空间
    SeqStack *stack=(SeqStack*)malloc(sizeof(SeqStack));
    //初始化为空
    for(int i=0;i<MAX_SIZE;i++)
    {
        stack->data[i]=NULL;
    }
    stack->size=0;
    return stack;
    cout<<"初始成功"<<endl;

}
//入栈操作
void Push_SeqStack(SeqStack *stack,void *data){
    //判断是否满足入栈的条件
    if(stack==NULL) return;
    if(data==NULL) return;
    if(stack->size==MAX_SIZE) return;
    stack->data[stack->size]=data;
    stack->size++;
}
//出栈操作
void Pop_SeqStack(SeqStack *stack){
    //判读栈是否为空的
    if(stack==NULL) return;
    if(stack->size==0) return;
    stack->data[stack->size-1]==NULL;
    stack->size--;
}
//返回栈顶元素
void* Top_SeqStack(SeqStack *stack)
{
    if(stack==NULL) return 0;
    if(stack->size==0) return 0;
    return stack->data[stack->size-1];

}
//判断栈是否为空
int IsEmpty(SeqStack *stack)
{
    if(stack==NULL) return 1;
    if(stack->size==0) return 1;
    return 0;
}
//返回栈的大小
int Size_SeqStack(SeqStack *stack)
{
    return stack->size;
}
void Free_SeqStack(SeqStack *stack)
{
    if(stack==NULL) return;
    stack->size=0;
    free(stack);
}
int main()
{
    //初始化一栈
    cout<<"开始初始化"<<endl;
    SeqStack *stack=Init_SeqStack();
    Person p1={"a",11};
    Person p2={"b",12};
    Person p3={"c",13};
    Person p4={"d",14};
    Person p5={"e",15};
    Push_SeqStack(stack,&p1);
    Push_SeqStack(stack,&p2);
    Push_SeqStack(stack,&p3);
    Push_SeqStack(stack,&p4);
    Push_SeqStack(stack,&p5);
    //打印栈中的元素
    cout<<"栈的size："<<stack->size<<endl;
    while(stack->size>0)
    {
        //先返回栈顶元素
        Person *tmp=(Person*)Top_SeqStack(stack);
        //打印栈顶元素
        cout<<"name:"<<tmp->name<<" "<<"age:"<<tmp->age<<endl;
        //栈顶元素出栈
        Pop_SeqStack(stack);
    }
    cout<<"栈的size："<<stack->size<<endl;
    Free_SeqStack(stack);
    cout<<"栈的size："<<stack->size<<endl;

}
