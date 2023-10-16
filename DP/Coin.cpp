// combine
// arrange: nested loop exchange
ll dp[2][1000001];
void solve(){
    int n, x; cin >> n >> x;
    vector<int> coin(n + 1);
    rep(i, 1, n){
        cin >> coin[i];
    }
    init(dp[0], 0);
    dp[0][0] = 1;
    rep(i, 1, n){
        rep(j, 0, x){
            dp[i & 1][j] = dp[!(i & 1)][j];
            if(j >= coin[i]){
                (dp[i & 1][j] += dp[i & 1][j - coin[i]]) %= MOD;
            }
        }
    }
    cout << dp[n & 1][x];
}
// Minimize coins nums
void solve(){
    int n, x; cin >> n >> x;
    vector<int> coin(n);
    lrep(i, 0, n){
        cin >> coin[i];
    }
    ll dp[x+1]; // init(dp, 0);
    dp[0] = 0;
    rep(i, 1, x){
        dp[i] = llinf;
        for(auto &j : coin){
            if(j <= i){
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    cout << (dp[x] == llinf ? -1 : dp[x]);
}