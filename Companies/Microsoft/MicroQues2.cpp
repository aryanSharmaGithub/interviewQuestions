#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> A){
    // set<int> s(a.begin(),a.end());
    // vector<int> ans;
    // for(auto i : s){
    //     if(i>0 and s.find((long long)i*2)!=s.end()){
    //         // cout<<i<<" "<<i*2<<endl;
    //         ans.push_back(i);
    //         s.erase((long long)i*2);
    //         s.erase(i);
    //         s.insert(-1);
    //         s.insert(-1);
    //     }
    // }
    // for(auto i : s) cout<<i<<" ";
    // cout<<endl;
    // if(s.size()!=0) return {};
    // return ans;

    vector<int> arr(1e6+1,0);
    for(auto i : A) arr[i] = 1;

    vector<int> ans;

    for(int i=1;i<(1e6+1)/2;i++){
        if(arr[i] == -1) continue;
        if(arr[i*2]==1){
            ans.push_back(i);
            arr[i*2] = -1;
            arr[i] = -1;
        }
    }

    for(auto i : arr) if(i==1) return {};

    return ans;
}

int main()
{
    // vector<int> A {1,3,4,2,6,8,16};
    vector<int> A {2,4,2,3};
    vector<int> ans = f(A);
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
}