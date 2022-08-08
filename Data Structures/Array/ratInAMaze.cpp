#include<bits/stdc++.h>
using namespace std;

    bool isSafe(vector<vector<int>> m, int n,int r,int c,vector<vector<int>> vis){
        if(r<0 || c<0 || r>=n || c>=n || m[r][c]==0 || vis[r][c]==1) return false;
        return true;
    }
    
    void help(vector<vector<int>> &m, int n,int r,int c,string &a, vector<string> &ans,vector<vector<int>> vis){
        if(r == n-1 && c == n-1){
            ans.push_back(a);
            return;
        }
        if(isSafe(m,n,r+1,c,vis)){
            a.push_back('D');
            vis[r+1][c] = 1;
            help(m,n,r+1,c,a,ans,vis);
            vis[r+1][c] = 0;
            a.pop_back();
        }
        if(isSafe(m,n,r-1,c,vis)){
            a.push_back('U');
            vis[r-1][c] = 1;
            help(m,n,r-1,c,a,ans,vis);
            vis[r-1][c] = 0;
            a.pop_back();
        }
        if(isSafe(m,n,r,c+1,vis)){
            a.push_back('R');
            vis[r][c+1] = 1;
            help(m,n,r,c+1,a,ans,vis);
            vis[r][c+1] = 0;
            a.pop_back();
        }
        if(isSafe(m,n,r,c-1,vis)){
            a.push_back('L');
            vis[r][c-1] = 1;
            help(m,n,r,c-1,a,ans,vis);
            vis[r][c-1] = 0;
            a.pop_back();
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        int r = 0;
        int c = 0;
        vector<string> ans;
        string a = "";
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        help(m,n,r,c,a,ans,vis);
        return ans;
    }

int main()
{
    vector<vector<int>> m = {{0, 1,1,1},{1,1,1,0},{1,0,1,1},{0,0,1,1}};
    int n = 4;
    // 0 1 1 1
    //  1 1 1 0
    //   1 0 1 1 
    //   0 0 1 1
    vector<string> a = findPath(m,n);
    for(auto i : a) cout<<i<<" "<<endl;
}