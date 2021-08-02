#include<iostream>
#include<vector>
using namespace std;

int divisible(int mainNumber,int n1, int n2)
{
    int total_n1=0;
    int total_n2=0;
    int total_n1n2=0;

    for(int i=n1;i<=mainNumber;i++)
    {
        if(i%n1==0)
        total_n1++;
    }

    for(int i=n2;i<=mainNumber;i++)
    {
        if(i%n2==0)
        total_n2++;
    }

    for(int i=n1*n2;i<=mainNumber;i++)
    {
        if(i%(n1*n2)==0)
        total_n1n2++;
    }
    return total_n1+total_n2-total_n1n2;
}

int main()
{
    int mainNumber = 40;
    cout<<divisible(mainNumber,5,7)<<endl;
}