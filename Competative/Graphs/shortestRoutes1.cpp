#include<bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic ignored "-Wc++11-extensions"
#define end "\n"
#define int long long int
#define pii pair<int,int>

int n,m;
vector<vector<pii> >g;
vector<int>dist;

void dijkastra(){
    for(int i=0;i<=n;i++) dist[i]=LONG_MAX;
    dist[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(make_pair(0,1));

    while(!pq.empty()){
        int dis = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist[u]<dis) continue;
        for(auto e: g[u]){
            int v = e.first;
            int c = e.second;
            if(dist[v]<=dis+c) continue;
            if(dist[v]>dis+c){
                dist[v]=dis+c;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1);
    for(auto i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back(make_pair(v,c));
    }
    dijkastra();
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}