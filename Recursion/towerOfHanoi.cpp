#include<iostream>
using namespace std;

void TOH(int n, char A, char B, char C)
{
    if(n==0)
    return;
    TOH(n-1,A,C,B); // A to C through B
    cout<<"Moved from "<<A<<" to "<<C<<endl;
    TOH(n-1,C,B,A); // C to B through A
    return;
}

int main()
{
    int n=3;
    TOH(n,'A','B','C');
    cout<<endl;
}