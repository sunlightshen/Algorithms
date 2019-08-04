#include<stdio.h>
int * out_t()
{
    static int r[3];
    r[0]=1;
    r[1]=2;
    r[2]=3;
    return r;
}
int main()
{
    int *p;
    p=out_t();
    //输出指针函数返回的数组
    for(int i=0;i<3;i++)
    {
        printf("%d ",*(p+i));
    }
}