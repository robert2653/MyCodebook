int n, nums[100], BIT[100], iiBIT[100][100];

// 1D-BIT
void modify(int x, int mod){
    for(; x <= n; x += (x&-x)){
        BIT[x] += mod;
    }
}
long long query(int a, int b) {
	long long ans = 0;
	for (; b; b -= b&-b) ans += BIT[b];
	for (a--; a; a -= a&-a) ans -= BIT[a];
	return ans;
}
// 2D-BIT // Forest Queries (Area)
void modify(int x, int y, int mod){
    for(; x <= n; x += (x&-x)){
        for(int tmp = y; tmp <= n; tmp += (tmp&-tmp)){
            iiBIT[x][tmp] += mod;
        }
    }
}
long long query(int x1, int y1, int x2, int y2){
    long long ans = 0;
    x1--, y1--;
    int tmp1, tmp2;
    
    for(tmp1 = x2; tmp1; tmp1 -= (tmp1&-tmp1)){
        for(tmp2 = y2; tmp2; tmp2 -= tmp2&-tmp2){
            ans += iiBIT[tmp1][tmp2];
        }
    }
    for(tmp1 = x1; tmp1; tmp1 -= (tmp1&-tmp1)){
        for(tmp2 = y2; tmp2; tmp2 -= tmp2&-tmp2){
            ans -= iiBIT[tmp1][tmp2];
        }
    }
    for(tmp1 = x2; tmp1; tmp1 -= (tmp1&-tmp1)){
        for(tmp2 = y1; tmp2; tmp2 -= tmp2&-tmp2){
            ans -= iiBIT[tmp1][tmp2];
        }
    }
    for(tmp1 = x1; tmp1; tmp1 -= (tmp1&-tmp1)){
        for(tmp2 = y1; tmp2; tmp2 -= tmp2&-tmp2){
            ans += iiBIT[tmp1][tmp2];
        }
    }
    return ans;
}