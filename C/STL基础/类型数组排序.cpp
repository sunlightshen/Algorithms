#include<iostream>
using namespace std;

//打印函数实现(模板只对他下面的函数起作用)
template<class T>
void PrintArray(T *arr,int len)
{
    for (int i = 0; i < len; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//排序算法实现(用模板的方式实现)S
template<class T>
void MySort(T *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            //从大到小排序
            if(arr[i]<arr[j])
            {
                    T temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
            }

        }
    }
}
int main()
{
    int arr[]={2,6,1,8,9,2};
    char a_arr[]={'a','b','d','o','f','l'};
    int a_len=sizeof(a_arr)/sizeof(char);
    cout<<"asdjkajshd:"<<a_len<<endl;
    int len=sizeof(arr)/sizeof(int);
    cout<<"----排序前----"<<endl;
    PrintArray(a_arr,a_len);
    cout<<"-- -排序后----"<<endl;
    MySort(a_arr,a_len);
    PrintArray(a_arr,a_len);

}