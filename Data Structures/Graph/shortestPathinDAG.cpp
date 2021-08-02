#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
    return;
}

void dfsSort(vector<int> &visited,stack<int> &s,int node,vector<int> adj[]){
    visited[node]=1;
    for(auto it: adj[node]){
        if(visited[it]==0) dfsSort(visited,s,it,adj);
    }
    s.push(node);
}

vector<int> shortestPath(vector<int> adj[], int V){
    vector<int> ans(V,INT_MAX);
    // Find topological sort in stack
    stack<int> s;
    vector<int> visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]) dfsSort(visited,s,i,adj);
    }
}

int main()
{
    int n = 7; // V is the number of vertecies
    vector<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,1,6);
    addEdge(adj,1,2);
    addEdge(adj,2,4);
    addEdge(adj,6,4);
    addEdge(adj,3,5);
}