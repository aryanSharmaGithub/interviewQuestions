#include<bits/stdc++.h>
using namespace std;

    void help(int n,int k, vector<int> &ds, vector<vector<int> > &ans,int index){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<n;i++){
            ds.push_back(i+1);
            help(n,k,ds,ans,i+1);
            ds.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> ds;
        
        help(n,k,ds,ans,0);
        return ans;
    }

    int main()
    {
        vector<vector<int> > ans = combine(4,2);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }