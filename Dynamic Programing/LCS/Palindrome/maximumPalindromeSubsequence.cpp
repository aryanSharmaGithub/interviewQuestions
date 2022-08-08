#include<iostream>
#include<cstring>
using namespace std;

int LCSPalindrome(string x,int n)
{
    char y[n];
    for(int i=0;i<n+1;i++)
    {
        y[i]=x[n-i];
        // cout<<y[i];
    }
    cout<<endl;
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=1;
                cout<<t[i][j]<<" ";
            }
            else if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
                cout<<t[i][j]<<" ";
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
                cout<<t[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return t[n][n];
}

int main()
{
    char x[]="aacabdkacaa";
    int n=strlen(x);
    cout<<LCSPalindrome(x,n)<<endl;
}