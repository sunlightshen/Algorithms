#include <stdio.h>
 
int max(int x, int y)
{
    return x > y ? x : y;
}
 
int main(void)
{
    /* p 是函数指针 */
    int (* p)(int, int) = max; // &可以省略，实际作用将函数相应的地址赋予给对应的函数指针。
    int a, b, c, d;
 
    printf("请输入三个数字:");
    //scanf("%d %d %d", & a, & b, & c);
    a=1;b=2;c=3;
 
    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c); 
    //指针函数很方便与实现对应的函数的复用
 
    printf("最大的数字是: %d\n", d);
 
    return 0;
}