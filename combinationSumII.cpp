#include<bits/stdc++.h>
using namespace std;

    void helper(vector<int>& cand, int target,vector<vector<int> > &ans,vector<int> &ds,int index){
        
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<cand.size();i++){
            if(i>index && cand[i]==cand[i-1]) continue;
            if(cand[i]>target) break;
            ds.push_back(cand[i]);
            helper(cand,target-cand[i],ans,ds,i+1);
            ds.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int> > ans;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,ans,ds,0);
        return ans;
    }

    int main()
    {
        vector<int> candidates{10,1,2,7,6,1,5};
        vector<vector<int> > ans = combinationSum2(candidates,8);
        for(int i = 0;i<ans.size();i++){
            for(auto it: ans[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }