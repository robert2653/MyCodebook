// now on a and want to reach b, the min steps, directed
int n, q;
int dp[30][maxn];
vector<vector<int>> cycles;
int no[maxn]; // Order、Can be in cycle，or out
int cycle_idx[maxn];
bool vis[maxn];
void set_out_of_cycle_no(int now, unordered_set<int> &done){
    if (done.find(now) != done.end())
        return;
    set_out_of_cycle_no(dp[0][now], done);
    done.insert(now);
    no[now] = no[dp[0][now]] - 1;
}
int will_go_to(int u, int k){ // return the node when walk k
    rep(i, 0, 18){
        if (k & (1 << i)){
            u = dp[i][u];
        }
    }
    return u;
}
void find_cycle(int now){
    unordered_set<int> appear;
    vector<int> vec;
    bool flag = true;
    while (appear.find(now) == appear.end()){
        appear.insert(now);
        vec.push_back(now);
        if (vis[now]){ // Didn't Find Cycle
            flag = false;
            break;
        }
        now = dp[0][now];
    }
    for (auto i : vec)  vis[i] = true;
    if (!flag)  return;
    int z = find(vec.begin(), vec.end(), now) - vec.begin(); // start pushing from last now
    int m = vec.size();
    vector<int> cycle;
    for (int i = z; i < m; i++){
        cycle.push_back(vec[i]);
    }
    cycles.push_back(cycle);
}
void solve(){
    cin >> n >> q;
    rep(u, 1, n){
        cin >> dp[0][u];
    }
    rep(i, 1, 18){ // Make Chart
        rep(u, 1, n){
            dp[i][u] = dp[i - 1][dp[i - 1][u]];
        }
    }
    rep(i, 1, n){
        if (!vis[i]) find_cycle(i);
    }
    ll idx = 0;
    memset(no, -1, sizeof(no));
    memset(cycle_idx, -1, sizeof(cycle_idx));
    unordered_set<int> done;
    for (auto &i : cycles){
        ll c = 0;
        for (auto &j : i){
            no[j] = c++;
            cycle_idx[j] = idx;
            done.insert(j);
        }
        idx++;
    }
    rep(i, 1, n) set_out_of_cycle_no(i, done);
    rep(i, 1, q){
        int u, v;   cin >> u >> v;
        // Same Cycle
        if (cycle_idx[u] == cycle_idx[v] && cycle_idx[u] != -1 && cycle_idx[v] != -1){
            int cyc_size = cycles[cycle_idx[u]].size();
            cout << (no[v] - no[u] + cyc_size) % cyc_size << endl;
        }
        else if (cycle_idx[u] == -1 && cycle_idx[v] == -1){ // Both are not in a Cycle
            if (no[u] > no[v]){
                cout << -1 << endl;
                continue;
            }
            ll jump = no[v] - no[u];
            if (will_go_to(u, jump) == v){
                cout << jump << endl;
            }
            else cout << -1 << endl;
        }
        else if (cycle_idx[u] == -1 && cycle_idx[v] != -1){ // v is in cycle，Smaller Binary Search
            int l = -1, r = n;
            while (l <= r){
                int m = (l + r) / 2;
                if (cycle_idx[will_go_to(u, m)] == cycle_idx[v]){
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (l != -1 && l <= n){
                int in_cycle_of_u = will_go_to(u, l);
                int cycle_size = cycles[cycle_idx[v]].size();
                cout << l + (no[v] - no[in_cycle_of_u] + cycle_size) % cycle_size << endl;
            }
            else cout << -1 << endl;
        }
        else { // u is death in the cycle，can't reach
            cout << -1 << endl;
        }
    }
}