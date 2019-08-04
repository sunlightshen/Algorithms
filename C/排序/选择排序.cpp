/*各种排序算法*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int keytype;

/*选择排序方法的实现*/
void selectsort(keytype k[],int n){
	int i,j ,min;
	keytype tmp;
	for(i=0;i<=n-2;i++){
		min=i;
		for(j=i;j<=n-1;j++)
		{
			if(k[j]<k[min])
				min=j;
		}
		if(min !=i){
			tmp=k[min];
			k[min]=k[i];
			k[i]=tmp;
		}
	}
} 
int main(){
	int a[]={7,5,1,2,4,9,3,1,6};
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	selectsort(a,9);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
}
