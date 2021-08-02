#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wc++11-extensions"
#define endl "\n"
using namespace std;

vector< vector<bool> > vis;
vector< vector<pair<int,int> > > path;
int n,m,sx,sy,ex,ey;
vector<pair<int,int> > moves;

bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m) return false;
    if(vis[x][y]) return false;
    return true;
}

void bfs(){
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy)); // Starting x axis and y axis

    while(!q.empty()){
        int cx = q.front().first; // current x
        int cy = q.front().second; // current y
        q.pop();
        for(auto m : moves){
            int mx = m.first; // movement x axis
            int my = m.second; // movement y axis
            if(isValid(cx+mx,cy+my)){ // If the movement FROM current point is valid or not
                q.push(make_pair(cx+mx, cy+my)); // If yes, we will explore that path also
				vis[cx+mx][cy+my] = true; // mark the node as visited
				path[cx+mx][cy+my] = make_pair(mx,my); //store the co ordinate in the path
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    n = 5, m=8;
//  Movement pairs
    moves.push_back(make_pair(-1,0));
    moves.push_back(make_pair(1,0));
    moves.push_back(make_pair(0,-1));
    moves.push_back(make_pair(0,1));

    //cin>>n>>m;
    vis.resize(n);
    path.resize(n);

    for(int i=0;i<n;i++) {vis[i].resize(m); path[i].resize(m);}
    string s = "#########.A#...##.##.#B##......#########";
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            path[i][j]=make_pair(-1,-1);
            char c= s[k];
            k++;
            if(c=='#') vis[i][j]=true; // Wall in grid
            else if(c=='A'){sx = i; sy = j;} // sx is starting x point and starting y point
            else if(c=='B'){ex = i; ey = j;} // ex is ending x point and ey is ending y point
        }
    }

    bfs();
    // Now we will have visited all the points.
    if(!vis[ex][ey]){
        cout<<"NO"<<endl; return 0; // If there is no way to go there
    }

    cout<<"YES"<<endl;
    // The path table will have cells in which movement by which they are approach will be present
    vector<pair<int,int> > ans;
    // ex, ey are the initial coordinate which will be present there for the backtracking movement to the starting point
    // (starting co-ordinate - movement by which approach = place from where movement was done (i.e. prev point))
    pair<int,int> end = make_pair(ex,ey);
    // This will be there till we reach the start point
    while(end.first!=sx || end.second!=sy){
        ans.push_back(path[end.first][end.second]);
        end.first-=ans.back().first;
        end.second-=ans.back().second;
    }
    // Now, we have the path in reverse so we reverse it to find the original path (path here means co-ordinates of the points which were used)
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    // Check if movement was up, down, left or right;
    for(auto c: ans){
        if(c.first==1 && c.second==0) cout<<"D";
        if(c.first==-1 && c.second==0) cout<<"U";
        if(c.first==0 && c.second==1) cout<<"R";
        if(c.first==0 && c.second==-1) cout<<"L";
    }


}