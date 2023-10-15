// Construct VScode
// 1. install vscode & msys2, check desktop path of vscode
// 2. open mingw64, not ucrt64, "pacman -S --needed base-devel mingw-w64-x86_64-toolchain"
// 3. add C:\\msys64\\mingw64\\bin to environment path
// 4. (re)open vscode, install C/C++, run, choose g++
// 5. open settings -> compiler -> add compilerPath "C:\\msys64\\mingw64\\bin\\g++.exe"

// Init
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define lrep(i, st, n) for(int i = st; i < n; i++)
#define rep(i, st, n) for(int i = st; i <= n; i++)
#define sz size()
#define pb(x) push_back(x)
#define ppb pop_back()
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define init(x, k) memset(x, k, sizeof(x));
#define vec_init(x, k) x.assign(x.size(), k);
#define lc 2*now
#define rc 2*now+1
#define mid (L+R)/2
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef struct {
    int from; int to;
    ll weight;
} edge;
typedef struct {
    ll sum;
} Node;
const ll llinf = 1e18;
const int inf = 1e9;
const int MOD = 1e9+7;
const int maxn = 2e5+5;

void solve(){

}
int main(){
    IO;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}