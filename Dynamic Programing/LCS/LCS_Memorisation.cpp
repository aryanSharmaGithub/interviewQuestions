#include<iostream>
using namespace std;

int static t[10][10];

int LCS_Memorisation(string x, string y, int n, int m)
{

    //Base Case
    if(n==0 || m==0)
    return 0;
    //Memorised Array
    if(t[n][m]!=-1)
    return t[n][m];
    //Code
    if(x[n-1]==y[m-1])
    return t[n][m]=1+LCS_Memorisation(x,y,n-1,m-1);
    else return t[n][m]=max(LCS_Memorisation(x,y,n-1,m),LCS_Memorisation(x,y,n,m-1));
    return t[n][m];
}

int main()
{
    memset(t,-1,sizeof(t));
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    int n = strlen(x);
    int m = strlen(y);

    cout<<LCS_Memorisation(x,y,n,m)<<endl;
}