const int maxn = 2505;
int m, n;
vector<edge> graph;
vll adj[maxn];
vl rev_adj[maxn];
ll dis[maxn];
bool vis[maxn] = {0};
bool nvis[maxn] = {0};
void dfs(int par, int now){
    if (vis[now] == 1) return;
    vis[now] = 1;
    for (auto [i, w] : adj[now]){
        if (i != par){
            dfs(now, i);
        }
    }
}
void rev_dfs(int par, int now){
    if (nvis[now] == 1) return;
    nvis[now] = 1;
    for (auto i : rev_adj[now]){
        if (i != par){
            rev_dfs(now, i);
        }
    }
}
void solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
        adj[u].push_back({v, w});
        rev_adj[v].push_back(u);
    }
    rep(i, 1, n) dis[i] = minf;
    dis[1] = 0;
    rep(i, 1, n){
        for (auto [u, v, w] : graph){
            if (dis[u] + w > dis[v]){
                dis[v] = dis[u] + w;
            }
        }
    }
    dfs(0, 1);
    rev_dfs(0, n);
    for (auto [u, v, w] : graph){
        if (dis[u] + w > dis[v] && nvis[u] && nvis[v] && vis[u] && vis[v]){
            cout << -1;
            return;
        }
    }
    cout << dis[n];
}