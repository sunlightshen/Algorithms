/*各种排序算法*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int keytype;
/*直接插入排序*/
void insertsort(keytype k[],int n){
	int i,j;
	keytype t,tmp;
	for(i=1;i<n;i++){
		tmp=k[i];
		j=i-1;
		while(j>=0 && tmp<k[j]){
			k[j+1]=k[j--];
			k[j+1]=tmp;
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
	insertsort(a,9);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
}
