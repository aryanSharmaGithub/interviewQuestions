#include<bits/stdc++.h>
using namespace std;

    vector<vector<int> > adj;
    
    vector<int> dfs(int src,string &labels, vector<int> &ans,vector<bool> &vis){
        if(vis[src]) return vector<int> ();
        vis[src]=true;
        vector<int> allInfo(26,0);
        allInfo[labels[src]-'a']++;
        for(int i=0;i<adj[src].size();i++){
            if(!vis[adj[src][i]]){
                vector<int> curr = dfs(adj[src][i],labels,ans,vis);
                // cout<<"src:"<<src<<" ";
                // for(auto i: curr) cout<<i<<" ";
                // cout<<endl;
                for(int i=0;i<26;i++){
                    allInfo[i]+=curr[i];
                }
                // cout<<"All Info: ";
                // for(auto i: allInfo) cout<<i<<" ";
                // cout<<endl;
            }
        }
        
        ans[src]=allInfo[labels[src]-'a'];
        return allInfo;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans(n,0);
        vector<bool> vis(n,false);
        dfs(0,labels,ans,vis);
        return ans;
    }

    int main()
    {
        vector<vector<int> > edge{{0,1},{0,2},{1,3},{3,4},{4,5}};
        int n = 6;
        string s = "cbabaa";
        vector<int> a = countSubTrees(n,edge,s);
    }