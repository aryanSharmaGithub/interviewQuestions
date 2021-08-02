#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

vector<ull> rangeSum(vector<ull> arr, vector<pair<ull,ull> > q){
    vector<ull> sumArr(arr.size(),0);
    sumArr[0]=arr[0];
    for(int i=1;i<arr.size();i++){
        sumArr[i]=sumArr[i-1]+arr[i];
    }
    vector<ull> ans;
    for(int i=0;i<q.size();i++){
        int l = q[i].first;
        int r = q[i].second;
        if(l==1){
            ans.push_back(sumArr[r-1]);
            continue;
        }
        ull temp = sumArr[r-1]-sumArr[l-2];
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    int n, q;
    cin>>n>>q;
    vector<ull> arr(n);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    vector<pair<ull,ull> > query;
    while(q--){
        int l,r;
        cin>>l>>r;
        query.push_back(make_pair(l,r));
    }
    vector<ull> ans = rangeSum(arr,query);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}