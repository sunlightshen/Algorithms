/*希尔排序*/
#include<stdio.h>

//设定交换函数
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
/*希尔排序算法实现*/
void shell_sort(int arry[],int len)
{
    int gap=(len+1)/2;
    while (gap>=1)
    {
        printf("%d \n",gap);
        /* code */
        for(int i=0;i<len-gap;i++)
        {
                for(int j=i;j>=0;j=j-gap)
                {
                    if(arry[j]<arry[j+gap])
                        swap(&arry[j],&arry[j+gap]);
                }
        }
        gap=gap/2;
    }
}
int main()
{
    int a[10]={1,0,9,7,8,3,2,4,5,6};
    shell_sort(a,10);
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }

}