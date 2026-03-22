#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ff first
#define ss second

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> pre(n+1), suf(n+1);
    for (int i = 0; i < n; i++)
        pre[i+1] = pre[i] + a[i];
    for (int i = n-1; i >= 0; i--)
        suf[i] = suf[i+1] + a[i];
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
