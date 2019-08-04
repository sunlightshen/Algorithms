/*插入排序的实现*/
#include<stdio.h>
#include<stdlib.h>
void insert_sort(int arry[],int len)
{
    int tmp,i,j;
    for(i=1;i<len;i++)
    {
        tmp=arry[i];
        for(j=i;j>=0&&arry[j-1]>tmp;j--)
            arry[j]=arry[j-1];
        arry[j]=tmp;
    }
}

int main()
{
    int a[10]={1,6,7,2,3,4,9,0,8,5};
    insert_sort(a,10);
    for(int i=0;i<10;i++)
    {
        printf("%d  ",a[i]);
    }

}