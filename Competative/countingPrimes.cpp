#include<bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#define ll long long
 vector<bool> check(1e7+2,true);
 vector<int> primes(1e7+2,0);
ll n = 1e7;

void solve(){
    for(ll p=2;p<=sqrt(n);p++){
        if(check[p]==true){
            for(ll i=p*p;i<=n;i+=p){
                check[i]=false;
            }
        }
    }
    primes[0]=0;
    primes[1]=0;
    for(ll i=2;i<=n;i++){
        primes[i]+=primes[i-1]+check[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int test;
    cin>>test;
    solve();
    while(test--){
        int l,r;
        cin>>l>>r;
        cout<<primes[r]-primes[l-1]<<"\n";
    }
}