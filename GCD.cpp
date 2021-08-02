#include<iostream>
#include<vector>
using namespace std;

int GCD(int n,int m)
{
    if(n>m)
    {
        while(m!=0)
        {
            int rem=n%m;
            n=m;
            m=rem;
        }
        return n;
    }
    else 
    {
        while(n!=0)
        {
            int rem=m%n;
            m=n;
            n=rem;
        }
        return m;
    }
}

int main()
{
    int n=42;
    int m=24;
    cout<<GCD(n,m)<<endl;
}