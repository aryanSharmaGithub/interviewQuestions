#include<bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wc++11-extensions"
//WRONG ANSWER
#define endl "\n"
#define a(x,y) make_pair(x,y)
int n,m;
vector< vector<int> >g;
map<pair<int,int>,pair<int,int> >par_mp;
vector<pair<int,int> > monster;
vector<pair<int,int> > moves;
pair<int,int> si,se;

bool isValid(int x,int y,int timer){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    if(g[x][y]<=timer) return false;
    return true;
}
bool isEscape(int x,int y,int timer){
    if(!isValid(x,y,timer)) return false;
    if(x==0 || y==0 || x==n-1 || y==m-1) return true;
    return false;
}
bool bfsEscape(){
    queue<pair<pair<int,int>,int> >q;
    q.push(make_pair(si,0));
    par_mp[si]=a(-1,-1);
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++; q.pop();
        for(auto mv: moves){
            int tx = cx+mv.first;
            int ty = cy+mv.second;
            if(isEscape(tx,ty,timer)){
                par_mp[a(tx,ty)]=a(cx,cy);
                se = a(tx,ty);
                return true;
            }
            if(isValid(tx,ty,timer)){
                par_mp[a(tx,ty)]=a(cx,cy);
                g[tx][ty]=timer;
                q.push(a(a(tx,ty),timer));
            }
        }
    }
    return false;
}
void preProcessLavaFlow(){
    queue<pair<pair<int,int>,int> >q;
    for(auto m: monster){
        q.push(make_pair(m,0));
    }

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int timer = q.front().second;
        timer++; q.pop();

        for(auto mv: moves){
            int tx = cx+mv.first;
            int ty = cy+mv.second;
            if(isValid(tx,ty,timer)){
                g[tx][ty]=timer;
                q.push(a(a(tx,ty),timer));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin >> n >> m;
    n=5,m=8;
    g.resize(n);
    for(int i=0;i<m;i++) g[i].resize(m);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         g[i][j]=iNT_MAX;
    //     }
    // }
    string s = "#########M..A..##.#.M#.##M#..#..#.######";
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c=s[k];
            k++;
            if(c=='#') g[i][j]=0;
            else if(c=='M') {g[i][j]=0; monster.push_back(make_pair(i,j));}
            else if(c=='A') {g[i][j]=0; si=make_pair(i,j);}
            else g[i][j]=INT_MAX;
        }
    }

    if(si.first==0 || si.second==0 || si.first==n-1 || si.second==m-1){
        cout<<"YES"<<endl<<"0"<<endl;
        return 0;
    }

    preProcessLavaFlow();

    if(!bfsEscape()){
        cout<<"NO"; return 0;
    }

        cout << "YES" << endl;
    pair<int,int> tmp = se;
    pair<int,int> tmp1 = par_mp[se];
    pair<int,int> ed = a(-1,-1); 
    vector<char> ans;
    while(tmp1 != ed)
    {
    
        if((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
        {
        ans.push_back('R');
        }
        if((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
        {
        ans.push_back('L');
        }
        if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
        {
        ans.push_back('D');
        }
        if((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
        {
        ans.push_back('U');
        }
        tmp = par_mp[tmp];
        tmp1 = par_mp[tmp];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto c: ans)
    {
        cout << c;
    }
}