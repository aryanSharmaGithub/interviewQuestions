#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;

#define mp(x,y) make_pair(x,y)
#define int long long int
#define pii pair<int,int>

int n,m;
vector<int> dist;
vector<vector<pii> > g;

void dijkastra(){
    for(int i=1;i<n+1;i++) dist[i]=LONG_MAX;
    dist[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> >p;
    p.push(mp(0,1)); // x = distance, y = vertice

    while(!p.empty()){
        int dis = p.top().first;
        int u = p.top().second;
        p.pop();

        if(dist[u]<dis) continue;
        for(auto e: g[u]){
            int v = e.first;
            int c = e.second;
            if(dist[v]<=dis+c) continue;
            else{
                dist[v]=dis+c;
                p.push(mp(dist[v],v));
            }
        }
    }
}

int32_t main()
{
    cin>>n>>m;
    dist.resize(n+1);
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back(mp(v,c));
    }

    dijkastra();

    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}