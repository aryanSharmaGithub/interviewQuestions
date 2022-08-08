#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxi;
int f(int n,vector<long long> &dp,int a){
    if(n==0) return 0;
    if(n>maxi) return 1e9;
//     cout<<n<<endl;
    if(dp.at(n)!= -1) return dp.at(n);
    
    int pos = (n-a >= 0) ? 1 + f(n-a,dp,a+1) : 1e9;
    int neg = 1 + f(n+a,dp,a+1);
    
    return dp.at(n) = min(pos,neg);
}

int minRobotMoves(int n) {
    if(n==1) return 1;
    maxi = (n*(n+1))/2;
    vector<long long> dp(maxi+1, -1);
    
    int ans = f(n,dp,1);
//     cout<<ans<<endl;
    return ans;
//     return 0;
}

int main()
{
    cout<<minRobotMoves(4)<<endl;
}