#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}

vector<int> shortestPath(vector<int> adj[],int source,int V){
    vector<int> ans(V,INT_MAX);
    queue<int>q;
    q.push(source);
    ans[source]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(ans[node]+1<ans[it]){
                ans[it]=ans[node]+1;
                q.push(it);
            }
        }
    }
    return ans;
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
    vector<int> ans = shortestPath(adj,2,n);
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}