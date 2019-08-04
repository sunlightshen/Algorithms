#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
#define MAX 10
int *CreatArray()
{
    srand((unsigned int)time(NULL));
    int *arr=(int *)malloc(sizeof(int));
    for(int i=0;i<MAX;i++)
    {
        arr[i]=rand()%MAX;
    }

    return arr;
}
//打印输出数组
void PrintArray(int arr[],int max)
{
    for(int i=0;i<max;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//合并算法
void Merge(int arr[],int start,int end,int mid,int *temp)
{
    int i_start=start;
    int i_end=mid;
    int j_start=mid+1;
    int j_end=end;
    //表示辅助空间元素个数
    int length=0;
    while(i_start<=i_end&&j_start<=j_end)
    {
        if(arr[i_start]<arr[j_start])
        {
            temp[length]=arr[i_start];
            length++;
            i_start++;
        }
        else
        {
            temp[length]=arr[j_start];
            j_start++;
            length++;
        }
        
    }
    while (i_start<=i_end)
    {
        /* code */
        temp[length]=arr[i_start];
        i_start++;
        length++;
    }
    while (j_start<=j_end)
    {
        /* code */
        temp[length]=arr[j_start];
        j_start++;
        length ++;
    }

    for(int i=0;i<length;i++)
    {
        arr[start+i]=temp[i];
    }
    

}


//创建排序函数
void MergeSort(int arr[],int start,int end,int *tmp)
{
    if(start>=end)
        return;
    //首先对数组进行分组
    int mid=(start+end)/2;
    MergeSort(arr,start,mid,tmp);
    MergeSort(arr,mid+1,end,tmp);
    //将分段的数组进行合并
    Merge(arr,start,end,mid,tmp);

}
int main()
{
    //创建数组
    int *myArry=CreatArray();
    cout<<"原始数组"<<endl;
    PrintArray(myArry,MAX);
    //开辟指针空间
    int *temp=(int *)malloc(sizeof(int)*MAX);
    MergeSort(myArry,0,MAX-1,temp);
    cout<<"排序后的数组"<<endl;
    PrintArray(myArry,MAX);
    free(temp);
    free(myArry);
}
