/*
        字符串匹配的KMP算法的实现
*/
#include<iostream>
#include<cstring>
using namespace std;

//next数组的获取
void get_next(char* T,int *next)
{
    //位置初始化
    int i,j;
    next[0]=-1;
    j=-1;
    i=0;
    int len=strlen(T);
    while(i<len)
    {
        cout<<"I:"<<i<<"------"<<"J:"<<j<<endl;
        if(-1==j || T[i]==T[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
        
        
    }
                                                                                                                                                                                                                                   

}
//KMP匹配算法的实现
/*
    @parameter s:被匹配字符串
    @parameter t:待匹配字符串
    @parameter pos: 初始搜索位置
*/
int index_KMP(char* S,char* T,int pos)
{
    
    int i=pos;
    int j=0;
    int next[255];
    get_next(T,next);
    int lens=strlen(S);
    int lent=strlen(T);
    while(i<lens&&j<lent)
    {
        if(j==-1||S[i]==T[j])//连个字母比较相等
        {
            ++i;
            ++j;
        }
        else
        {
            j=next[j];
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
    char T[]="abcdsssabcdalbzc";
    int pos=index_KMP(S,T,0);
    cout<<"匹配的位置："<<pos<<endl;

}
