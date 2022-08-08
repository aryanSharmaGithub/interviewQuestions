// #include<bits/stdc++.h>
// using namespace std;

// int frogJump(vector<int> height, int n,vector<int> &t, int k){
//     // if(k>height.size()) return 0;
//     // if(n==0) return 0;
//     // int ans = INT_MAX;
//     // for(int i=1;i<=k;i++){
//     //     int a = INT_MAX;
//     //     if(n>=i) a = frogJump(height,n-i,t,k) + abs(height[n-i] - height[n]);
//     //     ans = min(a,ans);
//     // }
//     // return ans;
//     if(k>height.size()) return 0;
//     t[0] = 0;
//     // if(t[n]!=-1) return t[n];
//     // int m = INT_MAX;
//     // t[n] = m;
//     // for(int i=1;i<=k;i++){
//     //     if(i<=n) m = frogJump(height,n-i,t,k) + abs(height[n-i]-height[n]);
//     //     t[n] = min(t[n],m);
//     // }
//     for(int i=1;i<n;i++){
//         int m = 55;
//         for(int j=1;j<=k;j++){
//             if(i>=j) m = min(m,t[i-j] + abs(height[i-j]-height[i]));
//         }
//         t[i] = m;
//     }
//     return t[n-1];
// }

// int main() 
// {
//     vector<int> height = {30,50,60,20,40,20};
//     vector<int> t(7,10000);
//     cout<<frogJump(height,height.size(),t,3)<<endl;
// }
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