#include <stdio.h>

const int MAX = 3;

int main ()
{
   char  var[] = {'a', 'b', 'c'};
   int  i;
   char *ptr;

   /* 指针中的数组地址 */
   ptr = var;
   for ( i = 0; i < MAX; i++)
   {

      printf("存储地址：var[%d] = %x\n", i, ptr );//打印指针此时对应的地址
      printf("存储值：var[%d] = %c\n", i, *ptr );//打印此时指针变量对应的数组值

      /* 移动到下一个位置 */
      ptr++;
   }
   return 0;
}