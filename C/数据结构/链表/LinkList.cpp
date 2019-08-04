#include<iostream>
#include<cstdlib>
#include<cstring>
#define ElemType int;
using namespace std;
typedef struct{
    char name[60];
    int age;
    int score;
}Person;

/*创建节点*/
typedef struct LINKNODE{
    void *data;//无类型指针，指向任何数据
    struct LINKNODE *next;
}LinkNode;

/*创建链表*/

typedef struct LINKLIST{
    LinkNode *head;
    int size;
}LinkList;
//打印函数指针
typedef void (*PRINTLINKNODE)(void *);
//初始化链表
LinkList *Init_LinkList(){
    LinkList *list=(LinkList *)malloc(sizeof(LinkList));
    list->size=0;
    //头结点，不保存数据信息
    list->head=(LinkNode*)malloc(sizeof(LinkNode));
    list->head->data=NULL;
    list->head->next=NULL;
    return list;
}
//指定位置插入
void Insert_LinkList(LinkList *list,int pos,void* data){
    //创建新的节点
    if(list==NULL)
        return;
    if(data==NULL)
        return;
    LinkNode *newnode=(LinkNode*)malloc(sizeof(LinkNode));
    newnode->data=data;
    newnode->next=NULL;
    //找插入位置的节点
    LinkNode *pCurrent=list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrent=pCurrent->next;
    }
    //新节点入链表
    newnode->next=pCurrent->next;
    pCurrent->next=newnode;
    list->size++;
}
//删除指定位置值
void Remove_LinkList(LinkList *list,int pos){
    if(list==NULL)
    {
        return;
    }
    //判断位置是否合法
    if(pos<0||pos>=list->size)
    {
        return;
    }
    //找到删除节点
    LinkNode *pCurrennt=list->head;
    for(int i=0;i<pos;i++)
    {
        pCurrennt=pCurrennt->next;
    }
    LinkNode *pDel=pCurrennt->next;
    pCurrennt->next=pDel->next;
    free(pDel);
    list->size--;
}
//获得链表的长度
int Size_LinkList(LinkList *list){
    return list->size;
}
//查找数据
int Find_LinkList(LinkList *list,void *data){
    if(list==NULL)
        return 0;
    if(data==NULL)
        return 0;
    LinkNode *pCurrent=list->head;
    int i=0;
    while(pCurrent!=NULL)
    {
        if(pCurrent->data==data)
        {
            break;
        }
        i++;
        pCurrent=pCurrent->next;
    }
    return i;
}
//返回第一个节点数据
void* Front_LinkList(LinkList *list){
    return list->head->next->data;
}
//打印链表节点
void Print_LinkList(LinkList*list,PRINTLINKNODE print){
    if(list==NULL)
        return;
    //辅助指针
    LinkNode *pCurrent=list->head->next;
    while(pCurrent!=NULL)
    {
        print(pCurrent->data);
        pCurrent=pCurrent->next;
    }
    cout<<endl;
}
//释放链表内存
void FreeSpace_LinkList(LinkList *list){
    if(list==NULL)
        return;
    //辅助指针
    LinkNode *pCurrent=list->head;
    while(pCurrent!=NULL)
    {
        LinkNode *pNext=pCurrent->next;
        free(pCurrent);
        pCurrent=pNext;
    }
    list->size=0;
    free(list);
}
//ceshi1
void MyPrint(void *data)
{
    Person *p=(Person*)data;
    cout<<"name:"<<p->name<<" age:"<<p->age<<" score:"<<p->score<<endl;

}
void test()
{
    
    LinkList *list=Init_LinkList();
    Person p1={"a",18,92};
    Person p2={"b",18,93};
    Person p3={"c",18,94};
    Person p4={"d",18,95};
    Person p5={"e",18,96};
    
    Insert_LinkList(list,0,&p1);
    Insert_LinkList(list,0,&p2);
    Insert_LinkList(list,0,&p3);
    Insert_LinkList(list,0,&p4);
    Insert_LinkList(list,0,&p5);
    int c=Find_LinkList(list,&p1);
    Print_LinkList(list,MyPrint);
    LinkList *pl;
    Person *p=(Person*)Front_LinkList(list);
    cout<<p->age<<endl;
    FreeSpace_LinkList(list);
    
}
int main()
{
    test();
}
