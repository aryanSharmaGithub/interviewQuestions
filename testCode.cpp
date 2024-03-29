#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int n,int m){
    if(i<0 or i>=n or j<0 or j>=m) return false;
    return true;
}

void diffuseOne(vector<vector<int>> &field,int i,int j,int n,int m,vector<vector<int>> &vis){
    if(isSafe(i+1,j,n,m)) {
        vis[i+1][j] = 1;
        field[i+1][j] = 0;
    }
    if(isSafe(i-1,j,n,m)) {
        vis[i-1][j] = 1;
        field[i-1][j] = 0;
    }
    if(isSafe(i,j+1,n,m)) {
        vis[i][j+1] = 1;
        field[i][j+1] = 0;
    }
    if(isSafe(i,j-1,n,m)) {
        vis[i][j-1] = 1;
        field[i][j-1] = 0;
    }
    
    return;
}

void help(vector<vector<int>> field,int ans,int i,int j,int &finalAns,int n,int m,vector<vector<int>> &vis){
    if(j==m-1){
        finalAns = min(ans,finalAns);
        return;
    }
    
    if(isSafe(i+1,j,n,m) and field[i+1][j]!=0) {
        vis[i+1][j] = true;
        help(field,ans+1,i+1,j,finalAns,n,m,vis);
        vis[i+1][j] = false;
    }
    if(isSafe(i-1,j,n,m) and field[i-1][j]!=0) {
        vis[i-1][j] = true;
        help(field,ans+1,i-1,j,finalAns,n,m,vis);
        vis[i-1][j] = false;
    }
    if(isSafe(i,j+1,n,m) and field[i][j+1]!=0) {
        vis[i][j+1] = true;
        help(field,ans+1,i,j+1,finalAns,n,m,vis);
        vis[i][j+1] = false;
    }
    
}

int shortestPath(vector<vector<int>> &field)
{
    int n = field.size(), m = field[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(field[i][j]==0 and vis[i][j]==0){
                diffuseOne(field,i,j,n,m,vis);
                j++;
            }
        }
    }
    // vis.clear();
    vector<vector<int>> vis1(n,vector<int>(m,0));
    int ans = 0;
    int finalAns = INT_MAX;
    for(int i=0;i<n;i++){
        if(vis1[i][0]==1){
            help(field,ans,i,1,finalAns,n,m,vis1);
        }
    }
    return finalAns;
}


int main(){
    // vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
    // string s = "catsanddog";
    // vector<string> a =  wordBreak(5,dict,s);
    // for(auto i  : a) cout<<i<<" ";
    vector<vector<int>> s = {{1, 1, 1, 1},{1 ,1 ,1 ,1 },{1 ,1 ,0 ,1},{0 ,1 ,1 ,1}};
    cout<<shortestPath(s)<<endl;
}