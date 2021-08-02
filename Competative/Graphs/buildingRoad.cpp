#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"

using namespace std;

int n,m;
int connected=0;
vector<bool> vis;
vector<vector<int> > g; // Graph
vector<int> lead;

void dfs(int u){
    vis[u]=true;
    for(auto v: g[u]){
        if(!vis[v]) dfs(v);
    }
}

void solve(){
    for(auto i=1;i<=n;i++){
        if(!vis[i]){
            connected++;
            lead.push_back(i);
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);

    for(auto i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve();

    cout<<connected-1<<endl;

    if(connected>1){
        int u = lead[0]; int v;
        for(auto i=1;i<connected;i++){
            v = lead[i];
            cout<<u<<" "<<v<<endl;
            u = v;
        }
    }
}