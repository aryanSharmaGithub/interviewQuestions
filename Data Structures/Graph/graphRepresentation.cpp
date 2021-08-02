#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    int m;
    cin>>n>>m;
    // This is the adjecency list method (best method for graph)
    vector<int> adj[n+1]; // We created an array of type vector<int> so that we can store values in vector(value of where the edge will go)
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    // if we need to add weight too then we will use vector of type pairs <int,int> and push like adj[u].push_back({v,w});
    // for directed graph, we cant use reverse condition so adj[v].push_back(u) will not be there.
    
    // We can use adjecency matrix too but it will take space complexity of O(N^2) which is not good while this takes O(N+2E).
    // We took here matrix till n+1 because here we take 1 based indexing. It means that we start the index of graph by 1 so we
    // need n+1th space to store the nth element (due to indices starting from 0). Had it been 0th indexing, we would have taken
    // adj[n];
}