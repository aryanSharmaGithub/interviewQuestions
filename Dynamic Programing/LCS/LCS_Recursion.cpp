#include<iostream>
using namespace std;

int LCS_Recursive(string x, string y, int n,int m)
{
    //Base case
    if(n==0 || m==0)
    return 0;
    if(x[n-1]==y[m-1])
    return 1+ LCS_Recursive(x,y,n-1,m-1);
    else return max(LCS_Recursive(x,y,n-1,m),LCS_Recursive(x,y,n,m-1));
}

int main()
{
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    int n=strlen(x);
    int m=strlen(y);
    cout<<LCS_Recursive(x,y,n,m)<<endl;
}