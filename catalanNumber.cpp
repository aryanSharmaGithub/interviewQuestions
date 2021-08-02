#include<iostream>
using namespace std;


// Numbers which are in the form of sumission(n*n(i)) where i ranges from 0 to n-1. 
int catalan(int n){
    // Base case so that 0 and 1st digit get initialised by 1
    if(n<=1){
        return 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+= catalan(i)*catalan(n-i-1); // Because we take from 0, we need to use n-i-1.
    }
    return ans;
}



int main()
{
    int n =9;
    cout<<catalan(n)<<endl;
}