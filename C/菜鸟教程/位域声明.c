#include <stdio.h>
#include <string.h>
 
struct
{
  unsigned int age : 3;
} Age;
 
int main( )
{
   Age.age = 4;
   printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );
 
   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );
 
   Age.age = 8; // 二进制表示为 1000 有四位，超出
   //警告表示数据超出位于定义的内存，因此数据将不显示。所以最后输出的数据为0;
   printf( "Age.age : %d\n", Age.age );
   return 0;
}