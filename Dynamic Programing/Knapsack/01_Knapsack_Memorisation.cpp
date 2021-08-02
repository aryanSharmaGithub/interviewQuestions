#include<iostream>
using namespace std;

int static t[102][1002];
int knapsack(int wt[],int val[], int w, int n)
{
    //Base Condition
    if(n==0||w==0)
    {
        return 0;
    }
    //Memorisation Conversion code
    if(t[n][w]!=-1)
    {
        return t[n][w];
    }
    //Choice diagram code
    if(wt[n-1]<=w)
        return t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    else
    return t[n][w]=knapsack(wt,val,w,n-1);
}

int main()
{
    memset(t,-1,sizeof(t));
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w=7;
    int n=4;
    cout<<knapsack(wt,val,w,n)<<endl;
}