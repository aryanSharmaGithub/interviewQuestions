#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int> coin, int n){
    sort(coin.begin(),coin.end(),greater<int>());
    int ans = 0;
    for(int i =0;i<coin.size();i++){
        if(n==0){
            return ans;
        }
        ans += n/coin.at(i);
        int temp= n/coin.at(i); // Value for which the same note can be used. (like if n = 400 so temp = 400/200 = 2 )
        n-=temp*coin.at(i);
    }
    return -1;
}

int main()
{
    int n = 11;
    vector<int> coin;
    // coin.push_back(2000);
    // coin.push_back(500);
    // coin.push_back(200);
    // coin.push_back(100);
    // coin.push_back(50);
    // coin.push_back(20);
    // coin.push_back(10);
    coin.push_back(5);
    coin.push_back(2);
    coin.push_back(1);

    cout<<coinChange(coin,n)<<endl;
}