void solve(){
    int n, m, noon, night;
    cin >> n >> m >> noon >> night;
    ll dis[n+1];    // 前k小，要用pq存，大的放top
    vll graph[n+1];
    bool vis[n+1]; // 如果要前k小，要用pq.top().first跟dis[pq.top().second]比，不用vis
    rep(i, 1, m){
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
    // noon 存-的
    rep(i, 1, n){
        dis[i] = inf;   vis[i] = 0;
    }
    pq.push({0, -noon, 1});
    dis[1] = 0;
    while(!pq.empty()){
        vl now = pq.top(); pq.pop();
        ll now_noon = -now[1], u = now[2];
        if(vis[u]) continue;
        for(auto [nxt, w] : graph[u]){
            if(noon < w) continue;  // 休息一天都走不到
            ll tmp = dis[u] + (now_noon >= w ? w : now_noon + night + w);
            if(tmp < dis[nxt]){
                dis[nxt] = tmp;
                pq.push({dis[nxt], -(now_noon >= w ? now_noon - w : noon - w), nxt});
            }
        }
        vis[u] = true;
    }
    if(dis[n] == inf) cout << -1 << endl;
    else cout << dis[n] << endl;
}