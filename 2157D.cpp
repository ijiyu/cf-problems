#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    vector<int> pre(n+1, 0);
    for (int i = 0; i < n; i++)
        pre[i+1] = pre[i] + a[i];
    vector<int> suf(n+1, 0);
    for (int i = n-1; i >= 0; i--)
        suf[i] = suf[i+1] + a[i];
    int out = 0;
    for (int i = 0; i < n; i++) {
        out = max(out, pre[i] - suf[i]); // if x = l
                                         //
                                         // // [50, 110, 130, 150, 170, 210] l = 100, r = 200
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
