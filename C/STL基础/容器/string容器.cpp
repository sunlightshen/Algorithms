/*
        C++中string容器的常见用法
*/




#include<iostream>
#include<string>
using namespace std;
int main()
{
    /*字符串容器的初始化*/
    string str1;//生成空的字符串
    string str2("123456789");//生成里面字符串的复制品
    string str3("12345",0,3);//返回从0开始长度为三的字符串
    string str4("012345",5);//返回前五个字符串
    string str5(5,'1');//生成五个1组成的字符串
    string(str2,2);//将字符串str2从下标2开始到结束组成新的字符串
    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    cout<<str4<<endl;
    cout<<str5<<endl;
    /*字符串的大小和容量问题*/
    string s="1234567";
    cout << "size=" << s.size() << endl;//返回字符的个数
    cout << "length=" << s.length() << endl;//同上两者效果相同
    cout << "max_size=" << s.max_size() << endl;//返回string对象中最多包含的字符个数，超出会抛出异常*(电脑内存上可以存储的)
    cout << "capacity=" << s.capacity() << endl;//重新分配内存之前，string对象肯能包含的最大字符数量


    /*string 字符串的比较*/
    //字符串的比较是比较的ASII码
    cout<<"---字符串进行比较----"<<endl;
    string A("aBcd");
    string B("Abcd");
    string C("123456");
    string D("123dfg");

    // "aBcd" 和 "Abcd"比较------ a > A
    cout << "A.compare(B)：" << A.compare(B)<< endl;                          // 结果：1

    // "cd" 和 "Abcd"比较------- c > A(A的子串从索引2开始包含3个字符与字符串Bj进行比较)
    cout << "A.compare(2, 3, B):" <<A.compare(2, 3, B)<< endl;                // 结果：1

    // "cd" 和 "cd"比较 （A和B指定子串进行比较）
    cout << "A.compare(2, 3, B, 2, 3):" << A.compare(2, 3, B, 2, 3) << endl;  // 结果：0

    // 由结果看出来：0表示下标，3表示长度
    // "123" 和 "123"比较 (指定位置子串进行比较)
    cout << "C.compare(0, 3, D, 0, 3)" <<C.compare(0, 3, D, 0, 3) << endl;    // 结果：0




}