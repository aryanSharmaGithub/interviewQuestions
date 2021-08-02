#include<iostream>
#include<vector>
using namespace std;

void printDecOrder(int n)
{
    if(n==0)
    {   
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    printDecOrder(n-1);

}

void printIncOrder(int n)
{
    if(n==-1)
    return;
    printIncOrder(n-1);
    cout<<n<<" ";
}

int main()
{
    int n=10;
    printDecOrder(n);
    cout<<endl;
    printIncOrder(n);
    cout<<endl;
}