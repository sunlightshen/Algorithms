/*选择排序的实现*/
#include<stdio.h>
#include<stdlib.h>

//设定交换函数
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

//设定选在排序函数
void selection_sort(int array[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        int min=i;
        //注意每次寻找时替换的位置
        for(int j=i+1;j<len-1;j++)
        {
            if(array[min]>array[j])
                min=j;
            swap(&array[min],&array[i]);
        }
    }
}
int main()
{
    int a[10]={1,9,0,2,6,8,3,5,4,7};
    selection_sort(a,10);
    for(int j=0;j<10;j++)
    {
        printf("%d ",a[j]);
    }
}

