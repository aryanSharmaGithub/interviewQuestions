#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}

bool detectCycle(int V,vector<int> adj[]){
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            queue<pair<int,int> >q;
            q.push({i,-1}); // taken par in which first value is the val of node and second is the value of parent node(from where it came).
            vis[i]=1;
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second; // Just to check afterwards
                q.pop();
                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it,node}); // it will be the node to be traversed afterwards and because it came from the curr node, it will become its parent
                    }
                    else if(parent!=it) return true; // If parent!=it, that means some other person is parent of that child which is not good. So we declare true, i.e. cycle detected
                }
            }
        }
    }
    return false;
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
    cout<<detectCycle(n,adj)<<endl;
}