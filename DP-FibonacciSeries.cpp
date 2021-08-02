#include<iostream>
using namespace std;
int fib(int n)
{
    int result[n];
    result[0]=0;
    result[1]=1;
    for(int i=2;i<n+1;i++)
    {
        result[i]=result[i-1]+result[i-2];
    }
    return result[n];    
}
int main()
{
    int n=5;
    cout<<fib(5);
}