// Bit_Mask_DP, Travel Exactly Once
int dp[(1 << 20) - 1][20];
vector<int> rev_adj[20];
int n, m;
const int mod = 1e9 + 7;
void solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int u, v; cin >> u >> v;
        rev_adj[--v].push_back(--u);
    }
    dp[1][0] = 1;
    lrep(road, 1 << 1, 1 << n){
        // Not include 1
        if(road & 1 == 0) continue;
        // include n but not all walked
        if(road & (1 << (n - 1)) && road != ((1 << n) - 1)) continue;
        // DP
        for (int end = 0; end < n; end++) {
            // Not include end
			if ((road & (1 << end)) == 0) continue;
            // exclude end point is last road
			int pre_road = road - (1 << end);
			for (int pre_road_end : rev_adj[end]) {
                // pre_road_end is prev's end
				if ((road & (1 << pre_road_end))) {
					dp[road][end] += dp[pre_road][pre_road_end];
					dp[road][end] %= mod;
				}
			}
		}
    }
    cout << dp[(1 << n) - 1][n - 1];
}