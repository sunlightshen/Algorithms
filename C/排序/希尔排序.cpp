/*各种排序算法*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int keytype;

/*希尔排序方法的实现*/
void shellsort(keytype k[],int n){
	int i,j,flag,gap=n;
	keytype tmp;
	while(gap>1){
		gap=gap/2;
		do{
			flag=0;
			for(i=0;i<=n-gap-1;i++)
			{
				j=i+gap;
				if(k[i]>k[j])
				{
					tmp=k[j];
					k[j]=k[i];
					k[i]=tmp;
					flag=1;//防止多余的排列，节省时间 
				}
			}
		}while(flag!=0);
	} 
} 
int main(){
	int a[]={7,5,1,2,4,9,3,1,6};
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	shellsort(a,9);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
}
