
/*冒泡排序实现数组的从大到小排列*/
/*
        冒泡的思想是按顺序找出相应的最值，然后把他们放到对应的位置上去
*/
#include<stdio.h>
void bubble_sort(int arry[],int len)
{
    int i,j,tmp;
    for ( i = 0; i < len-1; i++)
    {
        /* code */
        for ( j = 0; j < len-1-i; j++)
        {
            /* code */
            if(arry[j]<arry[j+1])
            {
                tmp=arry[j+1];
                arry[j+1]=arry[j];
                arry[j]=tmp;
            }
        }
    }
    
}
int main()
{
    int a[10]={1,4,7,90,13,12,10,6,8,2};
    bubble_sort(a,10);
    for(int i=0;i<10;i++)
        printf("%d  ",a[i]);
    printf("\n");
}