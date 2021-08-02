#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

 // } Driver Code Ends


// Only see function. Idk input stuff;
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[],vector<int> &vis,int node,int parent){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) {
                if(dfs(adj,vis,it,node)) return true;
            }
            else if(parent!=it) return true;
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i])  if(dfs(adj,vis,i,-1)) return true;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends