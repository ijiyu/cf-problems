#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define ff first
#define ss second

void solve() {
    ll d;
    cin >> d;
    ll out = 0;
    for (ll x = 1; x <= d; x++)
        out += ceil(sqrt((d+1)*(d+1)-x*x))-ceil(sqrt(d*d-x*x));
    cout << out*4 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
