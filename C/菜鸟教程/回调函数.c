#include <stdlib.h>  
#include <stdio.h>
 
// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)())//回调函数的句柄形式
{
    //参数列表里对应的函数参数可以不用声明类型
    int m,n;
    m=1;n=2;
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue(m,n);
}
 
// 获取随机值
int getNextRandomValue(int a, int b)
{
    int c;
    c=a+b;
    return c;
}
 
int main(void)
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    //指针形式已经声明，不用声明虚参的参数列表。
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}