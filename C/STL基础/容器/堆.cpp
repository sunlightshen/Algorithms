#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
//设置比较规则函数
bool cmp(const int& a, const int& b)
{
    //实现从大到小排列
    return a > b;
}


int main()
{
    int a[10] = {1,5,2,6,3,7,8,4,9,0};
    //实现初始化
    vector<int> v1(a,a+10);
    cout<<"-----创建堆----"<<endl;
    make_heap(v1.begin(),v1.end(),cmp);
    //打印输出堆中元素
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<";";
    }
    cout<<endl;
    cout<<"-----跳出最后一个元素----"<<endl;
    //pop_heap实现
    pop_heap(v1.begin(),v1.end(),cmp);
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        cout<<*it<<";";
    }
    cout<<endl;
    cout<<"---- 实现堆排序-----"<<endl;
    //内置堆排序函数
    sort_heap(v1.begin(),v1.end(),cmp);

    for(int i=0; i<10; i++){
        cout << v1[i]<<";";
    }

    cout<<endl;

    return 0;
}
