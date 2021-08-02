#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#define ll long long
using namespace std;

vector<ll> prefix(string s){
    ll n = s.size();
    vector<ll> a(n,0);
    for(ll i=1;i<n;i++){
        ll j = a[i-1];
        while(j>0 && a[j]!=a[i]) j = a[j-1];
        if(s[i]==s[j]) j++;
        a[i]=j;
    }
    return a;
}

int main()
{
    string a;
    cin>>a;
    string b;
    cin>>b;

    vector<ll> pre = prefix(b);
    ll count = 0, i=0,j=0;
    while(i<a.size()){
        if(a[i]==b[j]){
            i++;j++;
        }
        else{
            if(j) j = pre[j-1];
            else i++;
        }
        if(j==b.size()) count++;
    }
    cout<<count;
}