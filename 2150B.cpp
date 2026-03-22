#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
const int mod = 998244353;
 
struct mint{
    int x;
 
    mint (){ x = 0;}
    mint (int32_t xx){ x = xx % mod; if (x < 0) x += mod;}
    mint (long long xx){ x = xx % mod; if (x < 0) x += mod;}
 
    int val(){
        return x;
    }
    mint &operator++(){
        x++;
        if (x == mod) x = 0;
        return *this;
    }
    mint &operator--(){
        if (x == 0) x = mod;
        x--;
        return *this;
    }
    mint operator++(int32_t){
        mint result = *this;
        ++*this;
        return result;
    }
    
    mint operator--(int32_t){
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint &b){
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint &b){
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    mint& operator*=(const mint &b){
        long long z = x;
        z *= b.x;
        z %= mod;
        x = (int)z;
        return *this;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint operator/=(const mint &b){
        return *this = *this * b.inv();
    }
    mint power(long long n) const {
        mint ok = *this, r = 1;
        while (n){
            if (n & 1){
                r *= ok;
            }
            ok *= ok;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        return power(mod - 2);
    }
    friend mint operator+(const mint& a, const mint& b){ return mint(a) += b;}
    friend mint operator-(const mint& a, const mint& b){ return mint(a) -= b;}
    friend mint operator*(const mint& a, const mint& b){ return mint(a) *= b;}
    friend mint operator/(const mint& a, const mint& b){ return mint(a) /= b;}
    friend bool operator==(const mint& a, const mint& b){ return a.x == b.x;}
    friend bool operator!=(const mint& a, const mint& b){ return a.x != b.x;}
    mint power(mint a, long long n){
        return a.power(n);
    }
    friend ostream &operator<<(ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
    explicit operator bool() const {
        return x != 0;
    }
};
 
// Remember to check MOD
 
struct factorials{
    int n;
    vector <mint> ff, iff;
    
    factorials(int nn){
        n = nn;
        ff.resize(n + 1);
        iff.resize(n + 1);
        
        ff[0] = 1;
        for (int i = 1; i <= n; i++){
            ff[i] = ff[i - 1] * i;
        }
        
        iff[n] = ff[n].inv();
        for (int i = n - 1; i >= 0; i--){
            iff[i] = iff[i + 1] * (i + 1);
        }
    }
    
    mint C(int n, int r){
        if (n == r) return mint(1);
        if (n < 0 || r < 0 || r > n) return mint(0);
        return ff[n] * iff[r] * iff[n - r];
    }
    
    mint P(int n, int r){
        if (n < 0 || r < 0 || r > n) return mint(0);
        return ff[n] * iff[n - r];
    }
    
    mint solutions(int n, int r){
        // Solutions to x1 + x2 + ... + xn = r, xi >= 0 
        return C(n + r - 1, n - 1);
    }
    
    mint catalan(int n){
        return ff[2 * n] * iff[n] * iff[n + 1];
    }
};
 
const int PRECOMP = 3e6 + 69;
factorials F(PRECOMP);
 
// REMEMBER To check MOD and PRECOMP
 
void Solve() 
{
    int n; cin >> n;
    
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    int curr = 0;
    mint ans = 1;
    for (int i = n; i >= 1; i--){
        if (2 * i == n + 1){
            curr += 1;
        } else if (2 * i <= n){
            curr += 2;
        } 
        
        if (curr < a[i]){
            cout << 0 << "\n";
            return;
        }
        
        ans *= F.C(curr, a[i]);
        curr -= a[i];
    }
    
    if (curr != 0){
        ans *= 0;
    }
    
    cout << ans << "\n";
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
