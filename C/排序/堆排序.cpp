/*
    大顶实现从的小到达的数据排序
*/
#include<iostream>
using namespace std;
void PrintArray(int arr[],int max)
{
    for(int i=0;i<max;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
    定义交换函数
    @parameter myArry 带交换的数组
    @parameter a 待交换位置a的下标
    @parameter b 待交换位置b的下标
*/
void MySwap(int arr[],int a,int b)
{
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

/*
    @parameter myArry 待调整的数组
    @parameter index 待调整的数组的下标
    @parameter len 待调整的数组的长度
*/
void HeapAdjust(int myArry[],int index,int len)
{
    //先保存当前节点的下标
    int max=index;
    //保存左右孩子的数组下标
    int lchild = index * 2 + 1;
    int rchild = index * 2 + 2;
    //max 节点可能会改变也坑不会改变
    //分别判断左子树和右子树的大小关系，并及时对数据进性调整
    if(lchild <len && myArry[lchild]>myArry[max])
    {
        max=lchild;
    }
    if(rchild <len && myArry[rchild]>myArry[max])
    {
        max=rchild;
    }
    if(max != index)
    {
        //对数据进行交换
        MySwap(myArry,max,index);
        //递归实现数据调整，保证调整之后后面的子树依然保存堆的特性
        //保证交换后数据不发生太大的变化
        HeapAdjust(myArry,max,len);
    }


}
//堆排序的实现
void HeapSort(int myArry[],int len){
    /*实现对的初始化*/
    //从最后一个非叶子节点开始
    for(int i=len/2-1;i>=0;i--)
    {
        //开始调整子树堆
        HeapAdjust(myArry,i,len);
    }
    cout<<myArry[0]<<endl;
        //交换堆顶元素和最后元素
    for(int i = len-1;i>=0;i--)
	{
        MySwap(myArry,0,i);
        //每次把最大值取出来后，对剩下的堆继续进行对的调整,进而得到第二大的数据
        HeapAdjust(myArry,0,i);
	}
}
int main()
{
    //创建堆排序的原始数据
    int myArry[]={4,2,8,0,5,7,1,3,9};
    cout<<"---排序前的数据---"<<endl;
    int len=sizeof(myArry)/sizeof(int);
    cout<<"____len____:"<<len<<endl;
    PrintArray(myArry,len);
    //开始堆排序
    HeapSort(myArry,len);
    cout<<"----排序后的数据---"<<endl;
    PrintArray(myArry,len);

}
