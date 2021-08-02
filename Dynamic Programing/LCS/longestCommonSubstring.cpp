#include<iostream>
using namespace std;

int longestCommonSubstring(string x, string y, int n, int m)
{
    int max=INT_MIN;
    int t[n+1][m+1];
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            t[i][j]= 0;
            else if(x[i-1]==y[j-1])
            t[i][j]=1+t[i-1][j-1];
            else t[i][j]=0;
        }
    }
    int row=0,colomn=0;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(max<t[i][j])
            {
                max=t[i][j];
                row=i;
                colomn=j;
            }
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    while(row>0 && colomn>0)
    {
        if(x[row-1]==y[colomn-1])
        {
            cout<<x[row-1];
            row--;
            colomn--;
        }
        else if(t[row-1][colomn]>t[row][colomn-1])
        row--;
        else colomn--;
    }
    cout<<endl;
    return max;
}

int main()
{
    char x[]="aacabdkacaa";
    char y[]="aacakdbacaa";
    int n=strlen(x);
    int m=strlen(y);
    cout<<longestCommonSubstring(x,y,n,m)<<endl;
}