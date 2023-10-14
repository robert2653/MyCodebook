// a^(m-1) ≡ 1 (mod m)
// a^(m-2) ≡ 1/a (mod m)
// EXP2: cout << fast_exp(x, fast_exp(y, p, MOD - 1), MOD)
// Filter + DP; DP save min factor，recur，factor decomposition
// FacNums = (x+1)(y+1)(z+1)...
// FacSum = (a^0+a^1...+a^x)(b^0+...+b^y)
// FacMul = N(x+1)(y+1)(z+1)/2
ll fast_exp(ll x, ll p, ll mod){
    ll ans = 1;
    while(p > 0){
        if(p & 1) ans = (ans * x) % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}
ll quick_mul(ll a, ll b){
    ll ans = 0;
    a %= MOD;
    while(b > 0){
        if(b & 1){
            ans = (ans + a) % MOD;
        }
        a = (a << 1) % MOD;
        b >>= 1;
    }
    return ans;
}