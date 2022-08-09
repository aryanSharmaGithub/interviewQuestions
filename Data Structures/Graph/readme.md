# Dijkastra

Idhar we take minimum distance jo hum given source to dest travel kar sakte hai. Like nikal hum har kisi ki skte hai.

## Steps

1. Make a dis array of size V. <br/>
2. Take a priority queue and push {dis, node} in it. <br/>
3. Run basic BFS. <br/>
4. Compare if the current distance is greater than the distance coming via node <br/>
    1. If yes, then update the value in dis array and push the {dis,node} in queue <br/>

> Code

``` c++
void dijkstras(vector<pair<int, int>> graph[], int src, int V){
    // use priority queue as min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // distance vector
    vector<int>dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    // normal BFS traversal
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        // traverse for the neighbors of u
        for(auto x : graph[u]){
            // x = {v, wt}
            int v = x.first;
            int wt = x.second;
            if(dist[v]>dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout<<"Vertex   Distance from src\n";
    for(int i=0; i<V; i++)
        cout<<i<<"\t"<<dist[i]<<endl;
}

```

**Time Complexity** - O(V<sup>2</sup>) (Can be improved to O(E logV)) <br/>
**Space Complexity** - O(E)

# Bellman Ford

Detect negative weighted cycle (which Dijkastra cannot). <br/>

1. Apply Dijkastra n-1 times.
2. Apply one more time.
    1. If value of any distance changes, there is a negative cycle at play.
    2. Otherwise there is no negative cycle present

> Code

``` c++

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(n+1,1e9);
    dis[src] = 0;
    
    // Dijkastra (n-1) times
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dis[u]!=1e9 and (dis[v] > dis[u] + wt)){
                dis[v] = dis[u] + wt;
            }
        }
    }
    
    // Cycle detection
    int flag = 0;
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
            
        if(dis[u]!=1e9 and (dis[v] > dis[u] + wt)){
            return -1;
        }
    }
    
    return dis[dest];
}

```