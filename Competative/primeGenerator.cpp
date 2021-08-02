#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;
// NOT CORRECT CODE
#define ll long long int
int N = 1000000;
vector<bool> sieve(N+1,true);

void createSieve(){
    for(int i=2;i<=sqrt(N);i++){
        if(sieve[i]==true){
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=false;
            }
        }
    }
}

vector<int> generatePrime(int r){
    vector<int> ds;
    for(int i=2;i<r;i++){
        if(sieve[i]==true) ds.push_back(sieve[i]);
    }
    return ds;
}

int main()
{
    int t;
    cin>>t;
    createSieve();
    while(t--){
        int l,r;
        cin>>l>>r;
        vector<int> primes = generatePrime(sqrt(r));
        vector<int> dummy(r-l+1,1);
        for(auto p:primes){
            int firstMultiple = (l/p)*p;
            if(firstMultiple<l) firstMultiple+=p;

            for(int j=max(firstMultiple,p*p); j<=r; j+=p){
                dummy[j-l]=0;
            }
        }

        for(int i=l;i<=r;i++){
            if(dummy[i-l]==1){
                cout<<i<<"\n";
            }
        }
        cout<<"\n\n";
    }
}