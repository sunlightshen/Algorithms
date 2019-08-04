#include <stdio.h>
#include <string.h>
 
int main ()
{
   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   char str4[12]="lo";
   int  len ;
 
   /* 复制 str1 到 str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );
 
   /* 连接 str1 和 str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );
 
   /* 连接后，str1 的总长度 */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );

   /*检测字符出现的位置*/
   char c='l';
   char *p;
   p=strchr(str1,c);
   printf("strchr(str1,'l') :%s\n",p);//第一次出现的位置实际上返回的是后面的字符串。

   /*检测字符串出现的位置*/

   char *m=strstr(str1,str4);
   printf("strstr(str1,str4) :%s\n",m);//第一次出现的位置返回的也是后面的字符串。
 
   return 0;
}