#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
    return;
}

	// vector<int>bfsOfGraph(int V, vector<int> adj[])
	// {
    //     // Practice code on GFG, not working here tho I will try to explain here (for more info on working, check vid or notes)
	//     // Code here
	//     vector<int> ans; // To store values
	//     queue<int> q; // To store the values to be traversed
	//     vector<int> vis(V,0); // The visited array initialised by 0 (as ques had 0 based indexing)
	//     q.push(0); // initialising 0th array
	//     vis[0] = 1; // Visited the 0th element (because our first element is 0, ya better say we start with 0 so we mark it present).
	//     while(!q.empty()){ // For condition 
	//         int node = q.front(); // Taking node for future traversal
	//         q.pop(); // Pop the current node so that others can follow
	//         ans.push_back(node); // Push the node in ans (now its role has been completed)
	        
	//         for(int it=0;it<adj[node].size();it++){
	//             if(!vis[it]){
	//                 q.push(it); //  push the values in array (all the values of adjency list so that they can be pushed)
	//                 vis[it]=1; // mark the pushed values as visited
	//             }
	//         }
	//     }
	//     return ans;
	// }

    void bfsUsingQueue(vector<int> adj[],queue<int> &q,vector<int> &visited,vector<int> &ans){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
    }
    
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    queue<int> q;
	    vector<int> visited(V,0);
	    vector<int> ans;
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            q.push(0);
	            visited[0]=1;
	            bfsUsingQueue(adj,q,visited,ans);
	        }
	    }
	    return ans;
	}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 1; v <= V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int n = 7; // V is the number of vertecies
    vector<int> adj[n];
    addEdge(adj,0,1);
    addEdge(adj,0,6);
    addEdge(adj,1,2);
    addEdge(adj,2,4);
    addEdge(adj,6,4);
    addEdge(adj,3,5);
    // printGraph(adj,n);
    vector<int> ans = bfsOfGraph(n,adj);
    for(int it=0;it<ans.size();it++){
        cout<<ans.at(it)<<" ";
    }
}