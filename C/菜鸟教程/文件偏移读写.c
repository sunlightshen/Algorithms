#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){   
    FILE *fp = NULL;
    fp = fopen("C:\\Users\\SG\\Desktop\\tmp\\test.txt", "r+");  // 确保 test.txt 文件已创建
    fprintf(fp, "This is testing for fprintf...\n");   
    fseek(fp, 10, SEEK_SET);
    if (fputc(65,fp) == EOF) {
        printf("fputc fail");   
    }   
    fclose(fp);
}