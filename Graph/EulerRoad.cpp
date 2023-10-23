// Undirected: check adj[i].sz == odd => IMPOSSIBLE，road.sz != m+1 => IMPOSSIBLE
// Directed: minimize to 1 -> 2, so check in_degree == out_degree
int n, m;
set<int> adj[maxn];// rev_adj[maxn];
int in[maxn];
void dfs(int now, vector<int> &road){
    while(!adj[now].empty()){
        int nxt = *adj[now].begin();
        adj[now].erase(nxt);
        dfs(nxt, road);
    }
    road.push_back(now);
}
void solve(){
    cin >> n >> m;
    init(in,  0);
    rep(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        in[v]++;
    }
    in[1]++;
    in[n]--;
    rep(i, 1, n){
        if(adj[i].size() != in[i]){
            cout << "IMPOSSIBLE";
            return;
        }
    }
    vector<int> road;
    dfs(1, road);
    if(road.size() != m+1){
        cout << "IMPOSSIBLE";
        return;
    }
    reverse(all(road));
    for(auto i : road) cout << i << " ";
}