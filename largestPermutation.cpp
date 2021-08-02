#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

    bool static comp(int &a, int &b){
        return a>b;
    }
    
    vector<int> KswapPermutation(vector<int> arr, int k)
    {
        unordered_map<int,int> m; // number, position;
        vector<int> order;
        int n = arr.size();
        for(int i=0;i<n;i++) {m[arr[i]]=i; order.push_back(arr[i]);}
        sort(order.begin(),order.end(),comp);
        int i=0;
        while(k>0){
            if(i>=n) break;
            if(order[i]!=arr[i]){
                int curr = arr[i];
                swap(arr[i],arr[m[order[i]]]);
                int temp = m[order[i]];
                m[order[i]]=i;
                m[curr]=temp;
                k--;
            }
            i++;
        }
        return arr;
    }

int main()
{
    vector<int> arr{4,3,1,2};
    int k = 3;
    vector<int> ans = KswapPermutation(arr,k);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}