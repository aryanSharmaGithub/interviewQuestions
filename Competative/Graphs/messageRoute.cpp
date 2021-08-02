#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;

int n,m;
vector<int> parent;
vector<bool> vis;
vector<vector<int> > g;

void bfs(){
    vis[1]=true;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(!vis[v]){
                vis[v]=true;
                parent[v]=u;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    vis.resize(n+1);
    parent.resize(n+1);
    g.resize(n+1);

    for(int i=0;i<=n;i++) parent[i]=-1;

    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs();

    if(parent[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    stack<int> s;
    int init = n;
    while(init!=-1){
        s.push(init);
        init = parent[init];
    }
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}