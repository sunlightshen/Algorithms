#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MaxSize 10;
typedef struct DynamicArray
{
    /* data */
    int* pAddr;//存储数据的地址
    int size;//当前对应的元素数
    int capacity;//容量，当前创建的空间能容纳多少元素
}Dynamic_Array;
/*创建对动态数组处理函数*/

//初始化函数
Dynamic_Array* Init_Array(){
    //申请内存
    Dynamic_Array *myArray=(Dynamic_Array*)malloc(sizeof(Dynamic_Array));
    //初始化
    myArray->size=0;
    myArray->capacity=MaxSize;
    myArray->pAddr=(int *)malloc(sizeof(int)*myArray->capacity);
    return myArray;
}
//插入(在数组的末尾插入新元素)
void PushBack_Array(Dynamic_Array *array,int value){
    if(array==NULL)
        return;
    //判断空间是否足够
    if(array->size==array->capacity)
    {
        //申请更大一块空间是旧空间的两倍
        int *newSpace=(int *)malloc(sizeof(int)*array->capacity*2);
        //拷贝数组到新空间
        /*可以利用realloc函数进行扩展*/
        memcpy(newSpace,array->pAddr,array->capacity*sizeof(int));
        //释放旧空间的内存
        free(array->pAddr);
        //更新空间
        array->capacity=array->capacity*2;
        array->pAddr=newSpace;
    }

    //插入新元素
    array->pAddr[array->size]=value;
    array->size++;
}
//插入(按位置进行插入)
void Insert_Array(Dynamic_Array *array,int pos,int value)
{
    if(array==NULL)
        return;
    //判断空间是否够用
    if(array->size==array->capacity)
    {
        //申请更大一块空间是旧空间的两倍
        int *newSpace=(int *)malloc(sizeof(int)*array->capacity*2);
        //拷贝数组到新空间
        /*可以利用realloc函数进行扩展*/
        memcpy(newSpace,array->pAddr,array->capacity*sizeof(int));
        //释放旧空间的内存
        free(array->pAddr);
        //更新空间
        array->capacity=array->capacity*2;
        array->pAddr=newSpace;
    }
    if(pos<0||pos>array->size-1)
        return;
    for(int i=array->size-1;i>=pos;i--)
    {
        array->pAddr[i+1]=array->pAddr[i];
    }
    array->pAddr[pos]=value;
    array->size++;
}
//根据位置删除
void RemoveByPos_Array(Dynamic_Array *array,int pos){
    if(array==NULL)
        return;

    if(pos<0||pos>array->size-1)
        return;
    for(int i=pos;i<array->size-1;i++)
    {
        array->pAddr[i]=array->pAddr[i+1];
    }
    array->size--;
}
//根据值删除
void RemoveByValue_Array(Dynamic_Array *array,int value){
    if(array==NULL)
        return;
    int pos;
    for(int i=0;i<array->size;i++)
    {
        //只删除value第一次出现的位置
        if(array->pAddr[i]==value)
        {
            pos=i;  
            break;
        }
    }
    RemoveByPos_Array(array,pos);
}
int Find_Array(Dynamic_Array *array,int value)
{
    if(array==NULL)
        return 0;
    int pos=-1;
    for(int i=0;i<array->size;i++)
    {
        if(array->pAddr[i]==value)
        {
            pos=i;
            break;
        }
    }
    return pos;
}
//释放内存
void FreeSpace_Array(Dynamic_Array *array){
    if(array==NULL)
        return;
    if(array->pAddr!=NULL)
        free(array->pAddr);
    free(array);
}
//打印
void Print_Array(Dynamic_Array *array){
    if(array==NULL)
        return ;
    for(int i=0;i<array->size;i++)
    {
        cout<<array->pAddr[i]<<" ";
    }
    cout<<endl;
}
//清空数组
void Clear_Array(Dynamic_Array *array){
    if(array=NULL)
        return ;
    array->size=0;
}
//获得动态数组容量
int Capacity_Array(Dynamic_Array *array){
    if(array==NULL)
        return 0;
    return array->capacity;
    
}
//获得动态数组当前元素个数
int Size_Array(Dynamic_Array *array){
    if(array==NULL)
        return 0;
    return array->size;
}
//根据位置获取某个位置元素
int At_Array(Dynamic_Array *array,int pos){
    if(array==NULL)
        return 0;
    return array->pAddr[pos];
}
//主程序
void test()
{
    Dynamic_Array *arr=Init_Array();
    for(int i=0;i<10;i++)
        PushBack_Array(arr,i);
    Insert_Array(arr,1,10);
    Print_Array(arr);
}
int main()
{
    test();

}