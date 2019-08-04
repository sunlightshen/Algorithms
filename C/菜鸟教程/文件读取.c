#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;
   char buff[255];
 
   fp = fopen("C:\\Users\\SG\\Desktop\\tmp\\test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1: %s\n", buff );
    //读完结束后指针移动到空格对应的位置
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
    //读完结束后指针已经实现换行，因为fgets可以实现读到换行符然后终止
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
 
}