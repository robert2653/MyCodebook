const int maxn = 2e5+5;
int n; 
ll from[maxn], to[maxn], gain[maxn];
ll dp[400005];
vll rev_proj[400005];
void compress(map<int, int> mp){
    int now = 0;
    for(auto &i : mp){
        mp[i.first] = ++now;
    }
    rep(i, 1, n){
        rev_proj[mp[to[i]]].push_back({mp[from[i]], gain[i]});
    }
}
void solve(){cin >> n;
    map<int, int> comp;
    rep(i, 1, n){
        cin >> from[i] >> to[i] >> gain[i];
        comp[from[i]] = 1, comp[to[i]] = 1;
    }
    compress(comp);
    rep(i, 1, 400004){
        dp[i] = dp[i - 1];
        for(auto [from, gain] : rev_proj[i]){
            dp[i] = max(dp[i], dp[from - 1] + gain);
        }
    }
    cout << dp[400004];
}
// Monotonic DP in campus contest, use monotonic stack
// first is lowest mountain, second is pref in stack