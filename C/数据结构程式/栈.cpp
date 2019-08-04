/*
	栈:开辟连续的内存空间
		设定栈底和栈顶变量 
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define STACK_INIT_SIZE 10 //设定栈的大小
#define STACKINCREMENT 10
typedef char ElemType;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;
/*初始化栈*/
void initStack(sqStack *s)
{
	/*开辟连续的栈空间首地址赋给*base*/
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!s->base) exit(0);
	s->top=s->base;//最开始栈顶等价于栈底 
	s->stacksize=STACK_INIT_SIZE;//设定栈的最大值
} 
/*入栈操作、压栈操作*/
void Push(sqStack *s,ElemType e){
	if(s->top-s->base>=s->stacksize)
	{
		//栈已满，需要追加空间 
		//realloc函数进行栈的追加 
		s->base = (ElemType *)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(ElemType));
		if(!s->base) exit(0);
		s->top=s->base+s->stacksize;
		s->stacksize=s->stacksize+STACKINCREMENT;//栈的最大容量发生改变 
	}
	//将栈顶的值加一，并为其赋值 
	*(s->top)=e;
	s->top++; 
} 
/*出栈操作*/
void Pop(sqStack *s,ElemType *e)
{
	if(s->top == s->base) exit(0) ;
	*e=*--(s->top);
 } 
 /*清空一个栈*/
 void ClearStack(sqStack *s){
 	s->top=s->base;
 } 
/*销毁一个栈*/
void DestroyStack(sqStack *s){
	int i,len;
	len = s->stacksize;
	for(i=0;i<len;i++)
	{
		free(s->base);
		s->base++;
	}
	s->base=s->top=NULL;
	s->stacksize=0;
} 
/*计算栈的容量*/
int StackLen(sqStack *s){
	return (s->top-s->base);
}

//打印输出栈中的数据 
void print(sqStack * q)
{
	ElemType c;
	sqStack *p=q;
  	if (p->top==p->base) {
    	printf("空栈\n");
  	}
  	while(p->top!=p->base){
  	c=*--(p->top);
    printf("%c ",c);
  }
  printf("\n");
}
/*主函数实现二进制数据转换为十进制数据*/
int main()
{
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	printf("请输入二进制数据");
	initStack(&s);//创建一个栈 
	scanf("%c",&c);
	while(c!='#'){
		Push(&s,c);
		scanf("%c",&c);
	}

	//计算栈的长度
	len=StackLen(&s);
	printf("\n栈中的元素为：\n");
	sqStack l=s;
	print(&l); 
	for(i=0;i<len;i++){
		Pop(&s,&c);
		sum=sum+(c-48)*pow(2,i);
	} 
	printf("\n转化为的十进制数据为:%d\n",sum);
	getche();
 } 
 
 
