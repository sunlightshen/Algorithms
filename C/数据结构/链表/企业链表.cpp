#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
using namespace std;

//定义节点
typedef struct LINKNODE{
    struct LINKNODE *next;
}LinkNode;
//遍历函数指针
typedef void(*PRINTNODE)(LinkNode*);
//比较函数指针
typedef int(*COMPARENODE)(LinkNode*,LinkNode *);
typedef struct  PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;

//链表节点
typedef struct LINKLIST
{
    /* data */
    LinkNode head;
    int size;
}LinkList;

//初始化链表
LinkList *Init_LinkList(){
    LinkList *list=(LinkList *)malloc(sizeof(LinkList));
    list->head.next=NULL;
    list->size=0;
    return list;
}
//插入
void Insert_LinkList(LinkList *list,int pos,LinkNode *data)
{
    //加入判断
    if(list==NULL)
        return;
    if(data==NULL)
        return;
    //判断位置是否合理
    if(pos<0||pos>list->size)
    {
        pos=list->size;
    }
    //查找插入位置
    LinkNode *pCurrent=&(list->head);
    for(int i=0;i<pos;i++)
    {
        pCurrent=pCurrent->next;
    }
    //插入新节点（不需要创建新节点）
    data->next=pCurrent->next;
    pCurrent->next=data;
    list->size++;

}

//删除
void Remove_LinkList(LinkList *list,int pos){
    if(list==NULL)
        return;
    if(pos<0||pos>list->size)
        return;
    LinkNode *pCurrent=&(list->head);
    for(int i=0;i<pos;i++)
        pCurrent=pCurrent->next;
    pCurrent->next=pCurrent->next->next;
    list->size--;

}

//查找
int Find_ListList(LinkList *list,LinkNode *data,COMPARENODE compare){
    int index=1;
    int flag=-1;
    if(list==NULL)
        return 0;
    if(data==NULL)
        return 0;
    LinkNode*pCurrent=list->head.next;
    while (pCurrent!=NULL)
    {
        /* code */
        if(compare(pCurrent,data)==0)
        {
            flag=index;
            break;
        }
        pCurrent=pCurrent->next;
        
    }
    return flag;

    
}

//返回链表大小
int Size_LinkList(LinkList *list)
{
    return list->size;

}
//打印链表是利用回调函数来实现的
//打印链表
void Print_LinkList(LinkList *list,PRINTNODE print){
    if(list==NULL)
        return;
    LinkNode *pCurrent=list->head.next;
    while(pCurrent!=NULL)
    {
        print(pCurrent);
        pCurrent=pCurrent->next;
    }
    

}
//释放内存
void FreeSpace_LinkList(LinkList *list)
{
    if(list==NULL)
        return;
    free(list);
}
void MyPrint(LinkNode *data)
{
    Person *p=(Person *)data;
    cout<<"Name："<<p->name<<"  "<<"age:"<<p->age<<endl;
}
int MyCompare(LinkNode *node1,LinkNode *node2)
{
    Person *p1=(Person*)node1;
    Person *p2=(Person*)node2;
    if(strcmp(p1->name,p2->name) || p1->age==p2->age){
        return 0;
    }

}
int main()
{
    LinkList *list=Init_LinkList();
    //创建数据
    Person p1,p2,p3,p4,p5;
    //拷数据
    strcpy(p1.name,"a");
    strcpy(p2.name,"b");
    strcpy(p3.name,"c");
    strcpy(p4.name,"d");
    strcpy(p5.name,"e");
    p1.age=1;
    p2.age=3;
    p3.age=4;
    p4.age=5;
    p5.age=6;
    Insert_LinkList(list,0,(LinkNode*)&p1);
    Insert_LinkList(list,0,(LinkNode*)&p2);
    Insert_LinkList(list,0,(LinkNode*)&p3);
    Insert_LinkList(list,0,(LinkNode*)&p4);
    Insert_LinkList(list,0,(LinkNode*)&p5);
    Print_LinkList(list,MyPrint);
    cout<<"链表的长度为："<<list->size<<endl;
    cout<<"------------"<<endl;
    Remove_LinkList(list,2);
    Print_LinkList(list,MyPrint);
    FreeSpace_LinkList(list);
    cout<<"------------"<<endl;
    Person pp;
    strcpy(pp.name,"c");
    pp.age=4;
    int c=Find_ListList(list,(LinkNode*)&pp,MyCompare);
    if(c){
        cout<<"找到对应数据"<<endl;
    }
}