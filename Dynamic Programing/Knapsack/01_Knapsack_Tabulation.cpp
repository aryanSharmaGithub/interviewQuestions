#include<iostream>
using namespace std;

int knapsack(int val[],int wt[],int w,int n)
{
    int t[n+1][w+1];

    //Initialisation
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0)
            { 
                t[i][j]=0;
            }
        }
    }

    //Conversion (Note: 1 is used because 0 is initialised to 0)
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            t [i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else
            t[i][j]=t[i-1][j];
        }
    }
    return t[n][w];

}

int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w=7;
    int n=4;
    cout<<knapsack(val,wt,w,n)<<endl;
    return 0;
}