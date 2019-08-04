#include<iostream>
#include<cstdlib>
using namespace std;


/**先定义节点**/
typedef struct CIRCLELINKNODE
{
    /* data */
    struct CIRCLELINKNODE *next;

}CircleLinkNode;
/*定义链表*/
typedef struct CIRCLELINKLIST{
    CircleLinkNode head;
    int size;

}CircleLinkList;

/*设置数据表*/
typedef struct MUNUM
{
    /* data */
    CircleLinkNode node;
    int val;
}MyNumber;

/*设置打印函数*/
typedef void (*PRINTNODE )(CircleLinkNode*);

void MyPrint(CircleLinkNode *node)
{
    MyNumber *p1=(MyNumber*)node;
    cout<<p1->val<<endl;
}

/*设置比较函数*/
typedef int (*COMPARENODE)(CircleLinkNode *,CircleLinkNode *);

int compare(CircleLinkNode *node1,CircleLinkNode *node2)
{
    MyNumber *p1=(MyNumber *)node1;
    MyNumber *p2=(MyNumber *)node2;
    if(p1->val==p2->val)
        return 1;
    else
    {
        return 0;
    }
    
}

//循环链的初始化
CircleLinkList *Init_CircleLinkList()
{
    CircleLinkList *clist= (CircleLinkList*)malloc(sizeof(CircleLinkList *));
    clist->head.next=&(clist->head);
    clist->size=0;
    return clist;
}

//插入节点
void Insert_CircleLinkList(CircleLinkList *clist,int pos,CircleLinkNode *data)
{
    if(clist==NULL)
        return;
    if(data==NULL)
        return;
    //寻找插入位置
    CircleLinkNode *pCurrent=&(clist->head);
    for(int i=0;i<pos;i++)
    {
        pCurrent=pCurrent->next;
    }
    //插入位置
    data->next=pCurrent->next;
    pCurrent->next=data;
    clist->size++;
}

//根据函数值对列表进行删除
void RemoveByValue_CircleLinkList(CircleLinkList *clist,CircleLinkNode *data,COMPARENODE compare)
{
    if(clist==NULL)
        return;
    if(data==NULL)
        return;
    CircleLinkNode*pPrev=&(clist->head);
    CircleLinkNode *pCurrent=pPrev->next;
    for(int i=0;i<clist->size;i++)
    {
        if(compare(pCurrent,data))
        {
            pPrev->next=pCurrent->next;
            break;
        }
        pPrev=pCurrent;
        pCurrent=pPrev->next;
    }
    clist->size--;
}

//打印数据
void Print_CircleLinkList(CircleLinkList *&clist,PRINTNODE print)
{
    if(clist==NULL)
        return;
    CircleLinkNode *pCurrent=clist->head.next;
    for(int i=0;i<clist->size;i++)
    {
        print(pCurrent);
        pCurrent=pCurrent->next;
        if(pCurrent->next==&(clist->head))
                pCurrent=pCurrent->next;
    }
}
int main()
{

    CircleLinkList *clist=Init_CircleLinkList();
    MUNUM mn[100];
    for(int i=0;i<8;i++)
    {
        mn[i].val=i+1;
        Insert_CircleLinkList(clist,i,(CircleLinkNode *)&mn[i]);
    }
    Print_CircleLinkList(clist,MyPrint);
    cout<<"链表初始化完成"<<endl;
    /*开始约瑟夫问题的解决*/
    int index=1;
    CircleLinkNode *pCurrent=clist->head.next;
    while (clist->size>1)
    {
        /* code */
        if(index==3)
        {
            MyNumber *tmp=(MyNumber*)pCurrent;
            cout<<"第一次弹出的变量："<<tmp->val<<endl;
            CircleLinkNode *pNext=pCurrent->next;
            RemoveByValue_CircleLinkList(clist,pCurrent,compare);
            pCurrent=pNext;
            //仅需要判断当前节点就可以
            if(pCurrent==&(clist->head))
            {   
                pCurrent=pCurrent->next;
            }
            index=1;
        }

        pCurrent=pCurrent->next;
        if(pCurrent==&(clist->head))
        {
            pCurrent=pCurrent->next;
        }
        index++;

    }

    cout<<"--------"<<endl;
    cout<<"最后输出的数为："<<endl;
    Print_CircleLinkList(clist,MyPrint);
    
}