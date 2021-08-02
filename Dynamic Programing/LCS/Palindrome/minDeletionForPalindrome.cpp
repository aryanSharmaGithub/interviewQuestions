#include<iostream>
using namespace std;

int minDeletionForPalindrome(string x,int n)
{
    string y =x;
    reverse(x.begin(),x.end());
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
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
    int minDelete=abs(n-t[n][n]);
    return minDelete;
}

int LCS(string s1,int n)
{
    char s2[n];
    for(int i=0;i<n+1;i++)
    {
        s2[i]=s1[n-i];
        cout<<s2[i];
    }
    int dp[n + 1][n + 1];
    
    for (int i = 0; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    
    return n- dp[n][n];
}

int main()
{
    char x[]="adbceba";
    int n=strlen(x);
    cout<<minDeletionForPalindrome(x,n)<<endl;
}