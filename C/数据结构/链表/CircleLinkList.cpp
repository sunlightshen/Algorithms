#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

/*定义循环链表节点结构体*/
typedef struct CIRCLELINKNODE{

    CIRCLELINKNODE *next;
}CircleLinkNode;

/*定义节点结构体*/
typedef struct CIRCLELINKLIST{

    CircleLinkNode head;
    int size;
}CircleLinkList;

/**创建需要的数据集**/
typedef struct Person{
    CircleLinkNode node;
    char name[60];
    int age;
};

/*节点比较回调函数*/
typedef int(*COMPARENODE)(CircleLinkNode *,CircleLinkList *);

/*节点打印函数*/
typedef void(*PRINTNODE)(CircleLinkNode *);


/*设置链表的操作函数*/

//初始化函数
CircleLinkList* Init_CircleLinkList()
{
    CircleLinkList *clist=(CircleLinkList *)malloc(sizeof(CircleLinkList*));
    //将节点设置为指向
    clist->head.next=&(clist->head);
    clist->size=0;
    return clist;
}
//插入节点
void Insert_CirlceLinkList(CircleLinkList *clist,int pos,CircleLinkNode *data)
{
        if(clist==NULL)
           return;
        if(pos<0 || pos>clist->size)
            return;
        //创建辅助链表(注意这里定义是结构体的实体，不是指针)
        CircleLinkNode *pCurrent=&(clist->head);
        for(int i=0;i<pos;i++)
        {
            pCurrent=pCurrent->next;
        }
        data->next=pCurrent->next;
        pCurrent->next=data;
        //需要及时对链表进行维护
        clist->size++;
}
//删除节点
void Remove_CirlceListLink(CircleLinkList *clist,int pos)
{
    if(clist==NULL)
        return;
    if(pos<0 || pos>clist->size)
        return;
    //原因是会这个head在创建时是一个实体不是一个指针
    CircleLinkNode *pCurrent=&(clist->head);
    CircleLinkNode *pNext;
    for(int i=0;i<pos;i++)
    {
        pCurrent=pCurrent->next;
    }
    //注意缓存节点时的规则
    pNext=pCurrent->next;
    pCurrent->next=pNext->next;
    clist->size--;
}
//根据值删除
void RemoveByValue_CirlceLinkList(CircleLinkList *clist,CircleLinkNode data,COMPARENODE compare)
{

}
int Find_CircleLinkList(CircleLinkList *clist,CircleLinkNode *data,COMPARENODE compare)
{
    return 0;
}
//打印循环链表节点(调用打印的回调函数)
void Print_CircleLinkList(CircleLinkList *clist,PRINTNODE print)
{
    if(clist==NULL)
        return;
     CircleLinkNode *pCurrent=clist->head.next;
     int times=1;//可实现对链表的多次打印
     for(int i=0;i<clist->size*times;i++)
     {
        if(pCurrent==&(clist->head))
            pCurrent=pCurrent->next;
        print(pCurrent);
        pCurrent=pCurrent->next;
        
     }

}
//返回循环链表的大小
int Size_CirlceLinkList(CircleLinkList *clist)
{
    return clist->size;
}

//创建打印函数
void MyPrint(CircleLinkNode *data)
{
    cout<<"申光"<<endl;
    Person *p=(Person *)data;
    cout<<"Name："<<p->name<<"  "<<"age:"<<p->age<<endl;
}
//创建比较函数

int myCompare(CircleLinkNode*node1,CircleLinkNode *node2)
{
    //对节点数据进行强制转换
     Person *p1=(Person*)node1;
     Person *p2=(Person*)node2;
     if(strcmp(p1->name,p2->name) && p1->age==p2->age)
     {
         return 1;
     }
     else
     {
         return 0;
     }
     
}
int main()
{
    CircleLinkList *clist=Init_CircleLinkList();
    Person p1,p2,p3;
    strcpy(p1.name,"a");
    strcpy(p2.name,"b");
    strcpy(p3.name,"c");

    p1.age=1;
    p2.age=3;
    p3.age=4;

    Insert_CirlceLinkList(clist,0,(CircleLinkNode*)&p1);
    Insert_CirlceLinkList(clist,0,(CircleLinkNode*)&p2);
    Insert_CirlceLinkList(clist,0,(CircleLinkNode*)&p3);
    Print_CircleLinkList(clist,MyPrint);

    cout<<"删除测试！"<<endl;
    Remove_CirlceListLink(clist,1);
    Print_CircleLinkList(clist,MyPrint);

}