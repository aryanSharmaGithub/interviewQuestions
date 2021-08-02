#include<iostream>
#include<vector>
using namespace std;

vector<char> printLCS(string x,int n,string y,int m)
{
    vector<char> ans;
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
    int j=n,i=n;
    while(j>0 && i>0)
    {
        if(x[i-1]==y[j-1])
        {
            ans.push_back(x[i-1]);
            j--;
            i--;
        }
        else if(t[i-1][j]>t[i][j-1])
        {
            ans.push_back(x[i-1]);
            i--;
        }
        else
        {
            ans.push_back(y[j-1]);
            j--;
        }
    }
    while(i>0)
    {
        ans.push_back(x[i-1]);
        i--;
    }
    while(j>0)
    {
        ans.push_back(y[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    int n=strlen(x);
    int m=strlen(y);
    vector<char>v=printLCS(x,n,y,m);
    for(int i=0;i<v.size();i++)
    {
        cout<<v.at(i);
    }
    cout<<endl;
}