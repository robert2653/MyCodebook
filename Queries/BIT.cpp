typedef struct {
    int set_val, add, sum, val;
} node;
node tree[100];
int n, q, nums[100], _1D_BIT[100], _2D_BIT[100][100];

// 1D-BIT
void modify(int x, int mod){
    for(; x <= n; x += (x&-x)){
        _1D_BIT[x] += mod;
    }
}
ll query(int x, int y){
    ll ans = 0;
    for(; x; x -= (x&-x)){
        ans += _1D_BIT[x];
    }
    return ans;
}
// 2D-BIT // Forest Queries (Area)
void modify(int x, int y, int mod){
    for(; x <= n; x += (x&-x)){
        for(int tmp = y; tmp <= n; tmp += (tmp&-tmp)){
            _2D_BIT[x][tmp] += mod;
        }
    }
}
ll query(int x, int y){
    ll ans = 0;
    for(; x; x -= (x&-x)){
        for(int tmp = y; tmp; tmp -= (tmp&-tmp)){
            ans += _2D_BIT[x][tmp];
        }
    }
    return ans;
}