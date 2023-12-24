// Flight Discount
int n, m;
vll graph[maxn];
ll dis[maxn][2];    // 0 for not used
void dijkstra(){
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;  // 0 for w, 1 for u, 2 for discount
    for(int i = 1; i <= n; i++){
        dis[i][0] = dis[i][1] = inf;
    }
    dis[1][0] = dis[1][1] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        auto nxt = pq.top(); pq.pop();
        ll dist = nxt[0], u = nxt[1]; bool us = nxt[2];
        if(dis[u][us] < dist) continue; // is out of time, pass
        if(us){
            for(auto [v, w] : graph[u]){
                if(dis[u][1] + w < dis[v][1]){
                    dis[v][1] = dis[u][1] + w;
                    pq.push({dis[v][1], v, 1});
                }
            }
        }
        else {
            for(auto [v, w] : graph[u]){
                if(dis[u][0] + w < dis[v][0]){
                    dis[v][0] = dis[u][0] + w;
                    pq.push({dis[v][0], v, 0});
                }
                if(dis[u][0] + w / 2 < dis[v][1]){
                    dis[v][1] = dis[u][0] + w / 2;
                    pq.push({dis[v][1], v, 1});
                }
            }
        }
    }
    cout << min(dis[n][0], dis[n][1]);
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    dijkstra();
}