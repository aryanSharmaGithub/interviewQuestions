#include<vector>
#include<iostream>
using namespace std;

void longestRepeatingSubsequence(string x,int n)
{
    //vector<char> ans;
    string y=x;
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0||j==0)
            t[i][j]=0;
            else if(x[i-1]==y[j-1] && i!=j)
            t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    cout<<t[n][n]<<endl<<"Printing the Subsequence:"<<endl;
    int i=n,j=n;
    vector<char>ans;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1]&&i!=j)
        {
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(t[i-1][j]>t[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans.at(i);
    }
    cout<<endl;
}

int main()
{
    char x[]="AABEBCDD";
    int n=strlen(x);
    longestRepeatingSubsequence(x,n);
}