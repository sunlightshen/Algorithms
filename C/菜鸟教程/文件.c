
#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;
 
   fp = fopen("C:\\Users\\SG\\Desktop\\tmp\\test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
   //在使用结束后要对指针进行释放，防止其变为野指针，占用相关内存。
}