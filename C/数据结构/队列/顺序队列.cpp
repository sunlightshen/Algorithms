#include<iostream>
#include<cstring>
#include<cstdlib>
#define MAX_SIZE 100
using namespace std;
typedef struct SEQQUEUE
{
    /* data */
    void *data[MAX_SIZE];
    int size;
}SeqQueue;

//队列的处理函数
//初始化
SeqQueue* Init_SeqQueue(){
    //开辟内存
    SeqQueue *queue=(SeqQueue  *)malloc(sizeof(SeqQueue));
    for(int i=0;i<MAX_SIZE;i++)
    {
        queue->data[i]==NULL;
    }
    queue->size=0;
    return queue;
}
//入读操作
void Push_SeqQueue(SeqQueue* queue,void *data)
{
    //数组的左边当作对头
    if(queue==NULL)
        return;
    if(data==NULL)
        return;
    if(queue->size==MAX_SIZE)
        return;
    queue->data[queue->size]=data;
    queue->size++;
    cout<<"队列大小："<<queue->size<<endl;
}

//返回队头元素
void* Front_SeqQeueue(SeqQueue * queue)
{
    if(queue==NULL)
        return 0;
    if(queue->size==0)
        return 0;
    return queue->data[0];

}
//返回队尾元素
void *Back_SeqQueue(SeqQueue *queue)
{
    if(queue==NULL)
         return 0;
    if(queue->size==0)
         return 0;
    return queue->data[queue->size-1];

}
//返回大小
int Size_SeqQueue(SeqQueue *queue)
{
    if(queue==NULL)
        return 0;
    return queue->size;

}
//清空栈
void Clear_SeqQueue(SeqQueue *queue)
{
    if(queue==NULL)
        return;
    queue->size=0;

}

//出队
void Pop_SeqQueueu(SeqQueue *queue)
{
    //从头开始出
    if(queue==NULL)
        return;
    if(queue->size==0)
        return;
    //开始出队
    //注意循环基本的限制条件
    for(int i=0;i<queue->size-1;i++)
    {
        queue->data[i]=queue->data[i+1];
    }
	cout<<"duiliedaxiao："<<queue->size<<endl;
    queue->size--;
}
//释放队列内存
void Free_SeqQueue(SeqQueue *queue)
{
    if(queue==NULL)
        return;
    //释放内存
    free(queue);

}
typedef struct PERSON
{
    /* data */
    char name[20];
    int age;
}Person;

int main()
{
    //创建队列
    SeqQueue *queue=Init_SeqQueue();
    Person p1={"a",1};
    Person p2={"b",2};
    Person p3={"c",3};
    Person p4={"d",4};
    //向队列中插入元素
    Push_SeqQueue(queue,&p1);
    Push_SeqQueue(queue,&p2);
    Push_SeqQueue(queue,&p3);
    Push_SeqQueue(queue,&p4);
    //开始出对操作
    while(Size_SeqQueue(queue)>0)
    {
        //取出队头元素
        Person *p=(Person*)Front_SeqQeueue(queue);
        cout<<"Name:"<<p->name<<"  "<<"Age: "<<p->age<<endl;
        //出对进行下个元素
        Pop_SeqQueueu(queue);
    }
    //释放队列内存
    Free_SeqQueue(queue);

}
