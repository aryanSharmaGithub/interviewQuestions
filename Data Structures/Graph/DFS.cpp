#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
    return;
}

void dfs(int node,vector<int> adj[],vector<int> &ans,vector<int> &visited){
    ans.push_back(node);
    visited[node]=1;
    for(auto it : adj[node]){
        if(!visited[it]) dfs(it,adj,ans,visited);
    }
}

vector<int> dfsOfGraph(int V,vector<int> adj[]){
    vector<int> DFS;
    vector<int> visited(V+1,0);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            dfs(i,adj,DFS,visited);
        }
    }
    return DFS;
}

int main()
{
    int n = 7; // V is the number of vertecies
    vector<int> adj[n+1];
    addEdge(adj,1,2);
    addEdge(adj,2,7);
    addEdge(adj,2,3);
    addEdge(adj,3,5);
    addEdge(adj,7,5);
    addEdge(adj,4,6);
    vector<int> ans = dfsOfGraph(n,adj);
    for(int it=0;it<ans.size();it++){
        cout<<ans.at(it)<<" ";
    }
}