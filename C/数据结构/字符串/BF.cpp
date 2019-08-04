/*
        本程序通过百里搜索的算法实现字符串匹配问题
*/
#include<iostream>
#include<cstring>
using namespace std;
//BF算法实现
int index(char* S,char* T,int pos)
{
    int i=pos;
    int j=0;
    int lens=strlen(S);
    int lent=strlen(T);
    while(i<lens&&j<lent)
    {
        if(S[i]==T[j])//连个字母比较相等
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+2;//退回上次匹配的首位的下一位
            j=0;
        }
        
    }
    if(j==lent)
    {
        return i-lent;//字符串的位置

    }else
    {
        return 0;
    }
    

}
int main()
{
    char S[]="abchgfhgddefggoogle";
    char T[]="google";
    int pos=index(S,T,1);
    cout<<"匹配的位置："<<pos<<endl;

}
