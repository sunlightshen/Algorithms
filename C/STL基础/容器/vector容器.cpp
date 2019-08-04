#include<iostream>
#include<cstring>
using namespace std;
//关于STL中vector容器的学习，编译运行后边看代码，边看执行结果效果更佳，不过看别人的代码一百遍，不如自己动手写一遍 
#include <vector>//头文件
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector <int> v);
bool mycmpare(const int &a, const int &b){
    return a>b;
}
int main ()
{
    //创建vector对象三种常用的方式，此处存储元素类型是int，还可以是double、char、long long等基本数据类型，甚至是string基本字符序列容器 
    vector <int> v1;//不指定容器的元素个数的定义一个用来存储整型的向量容器
    cout<<"v1："<<endl; 
    print(v1);
    /*运行结果
        v1：
    大小为：0
    */ 
    
    vector <int> v2(5);//指定容器的元素个数的定义一个大小为10的用来存储整型的向量容器，默认初始化为0
    cout<<"v2："<<endl;
    print(v2);
    /*运行结果
    v2：
    大小为：5
    0 0 0 0 0
    */
    
    vector <int> v3(5,1);//也可指定初始值，此处指定为1
    cout<<"v3："<<endl;
    print(v3); 
    /*运行结果
    v3：
    大小为：5
    1 1 1 1 1
    */
    
    //另外事先指定不指定大小都无所谓，指定了大小也可以随时使用push_back()对vector容器进行尾部扩张
    v1.push_back(1);//向空的vector容器尾部扩张，追加元素为1
    cout<<"v1："<<endl; 
    print(v1); 
    v3.push_back(2);//向已有元素的vector容器尾部扩张，追加元素为2
    cout<<"v3："<<endl;
    print(v3);
    /*运行结果
    v1：
    大小为：1
    1
    
    v3：
    大小为：6
    1 1 1 1 1 2
    */
    
    //插入元素使用insert()方法，要求插入的位置是迭代器的位置，而不是元素的下标
    v3.insert(v3.begin(),3);//在最前面插入3
    cout<<"v3："<<endl;
    print(v3);
    
    v3.insert(v3.end(),3);//在末尾追加3，此处等同于push_back()
    cout<<"v3："<<endl;
    print(v3);
    /*运行结果
    v3：
    大小为：7
    3 1 1 1 1 1 2
    
    v3：
    大小为：8
    3 1 1 1 1 1 2 3
    */
     
    int i;
    for(i=0;i < v3.size();i++){//只可赋值到已扩张位置 
        v3[i]=i;
    }
    //要删除一个元素或者一个区间中的所有元素时使用erase()方法
    v3.erase(v3.begin()+2);//删除第2个元素，从0开始计数
    cout<<"v3："<<endl;
    print(v3); 
    /*运行结果
    v3：
    大小为：7
    0 1 3 4 5 6 7
    */
    v3.erase(v3.begin()+1,v3.begin()+3);//删除第1个到第3个元素区间的所有元素
    cout<<"v3："<<endl;
    print(v3);
    /*运行结果
    v3：
    大小为：5
    0 4 5 6 7
    */
    //由结果可知，erase()方法同insert()方法一样，操作的位置都只是迭代器的位置，而不是元素的下标
    
    //要想清空vector(),使用clear()方法一次性删除vector中的所有元素
    cout<<"v2："<<endl;
    print(v2);
    /*运行结果
    v2：
    大小为：5
    0 0 0 0 0
    */
    v2.clear();
    if(v2.empty()) cout<<"v2经过使用clear()方法后为空\n"; 
    print(v2);
    /*运行结果
    v2经过使用clear()方法后为空
    大小为：0
    */
    
    //要想将向量中某段迭代器区间元素反向排列，则使用reverse()反向排列算法,需要添加algorithm头文件 
    cout<<"v3反向排列前："<<endl;
    print(v3);
    reverse(v3.begin(),v3.end());//全部反向排列 
    cout<<"v3反向排列后："<<endl;
    print(v3); 
    /*运行结果
    v3反向排列前：
    大小为：5
    0 4 5 6 7
    
    v3反向排列后：
    大小为：5
    7 6 5 4 0
    */
    
    //要想将向量中某段迭代器区间元素进行排序，则使用sort()算法
    cout<<"v3升序排列前："<<endl;
    print(v3); 
    sort(v3.begin(),v3.end());//默认升序排列
    cout<<"v3升序排列后："<<endl;
    print(v3);
    /*运行结果
    v3升序排列前：
    大小为：5
    7 6 5 4 0
    
    v3升序排列后：
    大小为：5
    0 4 5 6 7
    */
    
    //自定义排序比较函数，此处降序
    cout<<"v3降序排列前："<<endl;
    print(v3);
    sort(v3.begin(),v3.end(),mycmpare); 
    cout<<"v3降序排列后："<<endl;
    print(v3);
    /*运行结果
    v3降序排列前：
    大小为：5
    0 4 5 6 7
    
    v3降序排列后：
    大小为：5
    7 6 5 4 0
    */
} 

void print(vector <int> v) 
{
    //cout<<"下标方式访问："<<endl;
    cout<<"大小为："<<v.size()<<endl; 
    int i;
    for(i=0;i< v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl<<endl;
    
    /*
    使用迭代器的方法访问vector容器
    vector<int>::iterator it; 
    for(it=v.begin(); it != v.end(); it++){
        cout<<*it<<' ';
    }
    cout<<endl<<endl;*/
}