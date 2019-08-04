#include <stdio.h>

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n")
    
//宏运算符可以用于表示函数对应形式。
int main(void)
{
   message_for(Carole, Debra);
   return 0;
}