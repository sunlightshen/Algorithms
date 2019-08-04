#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
    srand((unsigned) time (NULL));
    for(int i=0;i<10;i++)
    {
        int j;
        j=rand();
        cout<<j<<endl;

    }
}