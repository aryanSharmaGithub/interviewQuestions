#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;
//Test to check for github
int n,m,rooms;
vector<vector<bool> > visited;
bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m) return false;
    if(visited[x][y]) return false;
    return true;
}

void dfs(int i,int j,vector<pair<int,int> > moves){
    visited[i][j]=true;
    for(auto p: moves){
        if(isValid(i+p.first,j+p.second)){
            dfs(i+p.first,j+p.second,moves);
        }
    }
}

void connectedComponents(vector<pair<int,int> > moves){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                dfs(i,j,moves);
                ++rooms;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    visited.resize(n);
    for(int i=0;i<n;i++) visited[i].resize(m);

    vector<pair<int,int> > moves;
    moves.push_back(make_pair(-1,0));
    moves.push_back(make_pair(1,0));
    moves.push_back(make_pair(0,-1));
    moves.push_back(make_pair(0,1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            if(c=='#'){
                visited[i][j]=true;
            }
        }
    }

    connectedComponents(moves);
    cout<<rooms;
}