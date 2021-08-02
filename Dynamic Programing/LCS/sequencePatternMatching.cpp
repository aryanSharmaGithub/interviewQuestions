#include<iostream>
using namespace std;

bool isSequencePatternMatching(string x,int n, string y, int m)
{
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 ||j==0)
            t[i][j]=0;
            else if(x[i-1]==y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    if(n==t[n][m])
    return true;
    else return false;
}

int main()
{
    char x[]="AXGY";
    char y[]="ADXCPY";
    int n=strlen(x);
    int m=strlen(y);
    cout<<isSequencePatternMatching(x,n,y,m)<<endl;
}