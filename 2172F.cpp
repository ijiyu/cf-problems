#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll &i : p)
        cin >> i;
    vector<ll> pre(n);
    pre[0] = p[0];
    for (ll i = 1; i < n; i++)
        pre[i] = gcd(pre[i-1], p[i]);
    vector<ll> suf(n);
    suf[n-1] = p[n-1];
    for (ll i = n-2; i >= 0; i--)
        suf[i] = gcd(suf[i+1], p[i]);
    ll out = 0;
    for (ll i = 1; i < n - 1; i++)
        out += min(pre[i], suf[i]);
    out += pre[n-1];
    cout << out;
}
