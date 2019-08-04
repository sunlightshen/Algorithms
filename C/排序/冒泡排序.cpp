/*各种排序算法*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int keytype;

/*冒泡排序方法的实现*/
void bubblesort(keytype k[],int n){
	int i,j,tmp,flag=1;
	for(i=1;i<=n-1 && flag ==1;i++)
	{
		flag=0;
		for(j=0;j<=n-i-1;j++){
			if(k[j]>k[j+1])
			{
				tmp=k[j+1];
				k[j+1]=k[j];
				k[j]=tmp;
				flag=1;
			}
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
	bubblesort(a,9);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
}
