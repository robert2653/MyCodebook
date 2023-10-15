typedef struct{
    int from; int to;
    ll weight;
} edge;
const ll inf = 1LL << 62;
// NegCyc_Finding_Road
vector<edge> graph;
int main(){
    int src = 0;
    int n, m;    cin >> n >> m;
    vector<int> par(n+1), dis(n+1);
    rep(i, 0, m){
        int a, b, w; cin >> a >> b >> w;
        graph.push_back({a, b, w});
    }
    rep(i, 0, n+1) {
        dis[i] = 1e9 + 5;
    }
    dis[1] = 0;
    rep(i, 0, n + 1){
        src = 0;
        for(auto [a, b, w] : graph){
            if(dis[b] > dis[a] + w){
                dis[b] = dis[a] + w;
                par[b] = a;
                src = b;
            }
        }
    }
    if(src){
        vector<int> ans;
        cout << "YES" << endl;
        rep(i, 0, n + 1) src = par[src];
        ans.push_back(src);
        for(int i = par[src]; i != src; i = par[i]){
            ans.push_back(i);
        }
        ans.push_back(src);
        reverse(all(ans));
        for (auto i : ans){
            cout << i << " ";
        }
    }
    else {
        cout << "NO" << endl;
    }
}