//WRONG ANS

#include<iostream>
#include<vector>
using namespace std;

vector<char> longestCommonSubstring(string x, int n)
{
    string y=x;
    reverse(x.begin(),x.end());
    int max=INT_MIN;
    int t[n+1][n+1];
    
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 || j==0 ||i==1||j==1)
            t[i][j]= 1;
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
    vector<char> ans;
    while(row>0 && colomn>0)
    {
        if(x[row-1]==y[colomn-1]&& row!=colomn)
        {
            ans.push_back(x[row-1]);
            row--;
            colomn--;
        }
        else if(t[row-1][colomn]>t[row][colomn-1])
        row--;
        else colomn--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    char x[]="aacabdkacaa";
    int n=strlen(x);
    vector<char> ans=longestCommonSubstring(x,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans.at(i);
    }
    cout<<endl;
}