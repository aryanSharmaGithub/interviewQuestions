#include<iostream>
#include<vector>
using namespace std;

vector<int> minNoOfInsertionAndDeletion(string x,string y,int n,int m)
{
    vector<int> answerArray;
    int insert=0,deletion=0;
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0 || j==0)
            t[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    deletion=abs(n-t[n][m]);
    insert=abs(t[n][m]-m);
    answerArray.push_back(insert);
    answerArray.push_back(deletion);
    return answerArray;
}

int main()
{
    char x[]="geeksforgeeks";
    char y[]="geeks";
    int n=strlen(x);
    int m=strlen(y);
    vector<int>answer=minNoOfInsertionAndDeletion(x,y,n,m);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer.at(i)<<" ";
    }
    cout<<endl;
}