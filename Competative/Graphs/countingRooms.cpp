#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;

int n,m,rooms;
vector<vector<bool> > vis;
vector<pair<int,int> > moves;

bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m) return false; // Check out of bound error
    if(vis[x][y]) return false; // Check if ever visited or not
    return true; // If not visited or not out of bound, return true
}

void dfs(int i,int j){
    vis[i][j]=true; // Mark the point as visited so that repetation wont be there
    for(auto p: moves){ // To check for all movement around
    //isValid function checks if x,y co-ordinate is not going out of bounds or if it visited or not. If visited or out of bound, it returns false
        if(isValid(i+p.first,j+p.second)){ // p.first is first component of pair and p.second is second one (like (0,1), (-1,0) etc)
            dfs(i+p.first,j+p.second); // Do dfs from here
        }
    }
}

void connectedComponents(){ // This function is to check for different rooms
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j); // We will check for the whole room
                ++rooms; // As soon as we come out of dfs, it will mean we have completed one room hence room will be ++
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
    vis.resize(n);
    for(int i=0;i<n;i++) vis[i].resize(m);
    
    // Moves are up (-1,0), down (1,0), left (0,-1), right(0,1)
    moves.push_back(make_pair(-1,0));
    moves.push_back(make_pair(1,0));
    moves.push_back(make_pair(0,-1));
    moves.push_back(make_pair(0,1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin>>c;
            if(c=='#'){
                vis[i][j]=true; // Mark wall as true so that we can not visit them (rest all are false by default due to global variable)
            }
        }
    }

    connectedComponents();
    cout<<rooms;
}