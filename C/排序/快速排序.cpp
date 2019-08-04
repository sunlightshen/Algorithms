/*各种排序算法*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef int keytype;

/*交换函数的问题*/
 
void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
/*快速排序方法的实现*/
void quicksort(keytype k[],int s,int t){
	int i,j;
	if(s<t){
		i=s;
		j=t+1;
		while(1){
			do i++;
			while(!(k[s]<=k[i] || i==t));
			
			do j--;
			while(!(k[s]>=k[j]) || j==s);
			
			
			if(i<j)
				swap(&k[i],&k[j]);
			else 
				break;
		}
		//利用递归的思想 
		swap(&k[s],&k[j]);//与初始位置的值进行调换 
		quicksort(k,s,j-1);
		quicksort(k,j+1,t);
	}
	 
} 
int main(){
	int a[]={7,5,1,2,4,9,3,1,6};
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	quicksort(a,0,8);
	for(int i=0;i<9;i++)
	{
		printf("%d ",a[i]);
	}
} 
