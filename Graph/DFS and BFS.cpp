ll N = 1e6;
vector<int> adj[N];
bool vis[N];
void DFS(ll s){
    if(vis[s]) return;
    vis[s] = true;
    for(auto u: adj[s]){
        DFS(u);
    }
}
queue<ll> q;
ll dis[N];
void BFS(ll x){
    vis[x] = true;
    dis[x] = 0;
    q.push(x);
    while(!q.empty()){
        ll now = q.front();q.pop();
        for(auto nxt : adj[now]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            dis[nxt] = dis[now] + 1;
            q.push(nxt);
        }
    }
}