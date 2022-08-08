#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> f(vector<int> start,vector<int> end,int n){
    vector<vector<int>> ans;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        a[i] = {start[i],end[i]};
    }
    int count = 0;
    sort(a.begin(),a.end());
    vector<int> temp {a[0]};
    for(int i=1;i<n;i++){
        if(a[i][0]>temp[1]){
            ans.push_back(temp);
            temp[0] = a[i][0];
            temp[1] = a[i][1];
            count++;
        }
    }
    cout<<count<<endl;
    ans.push_back(temp);
    
    return ans;
}

int main()
{
    vector<int> start {5,2,3,7};
    vector<int> end {7,2,4,8};

    vector<vector<int>> ans = f(start,end,start.size());
    
    for(auto i : ans) cout<<i[0]<<" "<<i[1]<<endl;
}