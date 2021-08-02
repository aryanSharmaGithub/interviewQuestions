#include<bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#define pii pair<int,int>
void solve(){
    int pos,light;
    cin>>light>>pos;
    pos++;
    vector<pii> q;
    for(int i=0;i<light;i++){
        int l,r;
        cin>>l>>r;
        q.push_back(make_pair(l,r));
    }
    vector<int> temp(pos,0);
    for(auto i: q){
        int start = i.first - i.second;
        int end = i.first + i.second + 1;
        if(start>=0 ) temp[start]++;
        else temp[0]++;
        if(end<=pos) temp[end]--;
    }

    vector<ll> prefixSum(pos,0);
    prefixSum[0]=temp[0];
    for(int i=1;i<temp.size();i++){
        prefixSum[i] = prefixSum[i-1]+temp[i];
    }
    int maxVal = 0;
    int tempVal = 0;
    for(auto i: prefixSum){
        if(i==1) {tempVal=0;continue;}
        tempVal++;
        maxVal = max(maxVal,tempVal);
    }
    cout<<maxVal<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}