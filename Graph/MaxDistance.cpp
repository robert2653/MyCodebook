// 最大距離，使用拓樸，確保不會再被走過，要用queue
// 如果1走不到n，可能會被鬆弛，要dis[n] < 0
// 只是用單向圖
void print_ans(int n, vector<int> &par){
    deque<int> ans;
    int now = n;
    while(now != 1){
        ans.push_front(now);
        now = par[now];
    }
    ans.push_front(1);
    cout << ans.size() << endl;
    for(auto i : ans){
        cout << i << " ";
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    // int dis[maxn];
    vector<int> dis(n+1, -inf); dis[1] = 0;
    vi graph[n+1];
    vector<bool> vis(n+1, 0);
    vector<int> par(n+1);
    vector<int> in(n+1, 0);
    // priority_queue<pii, vii, greater<pii>> pq;
    queue<int> q;
    rep(i, 1, m){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        in[v]++;
    }
    // q.push({0, 1});
    rep(i, 1, n){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto nxt : graph[u]){
            if(dis[nxt] < dis[u] + 1){
                dis[nxt] = dis[u] + 1;
                par[nxt] = u;
            }
            in[nxt]--; if(in[nxt] == 0) q.push(nxt);
        }
        vis[u] = 1;
    }
    if(dis[n] < 0){
        cout << "IMPOSSIBLE";
    }
    else print_ans(n, par);
}