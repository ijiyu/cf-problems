#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<vector<ll>> a(n, vector<ll>(k));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
            cin >> a[i][j];

    for (ll i = 1; i < n; i++)
        for (ll j = 0; j < k; j++)
            a[i][j] |= a[i-1][j];
    
    while (q--) {
        ll m;
        cin >> m;
        ll minn = 0;
        ll maxx = n-1;
        bool off = false;
        while (m--) {
            ll r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if (o == '<') {
                ll le = -1, ri = n;
                while (le + 1 !=  ri) {
                    ll mid = (le + ri) / 2;
                    if (a[mid][r] < c)
                        le = mid;
                    else
                        ri = mid;
                }
                maxx = min(maxx, le);
            }
            else {
                ll le = -1, ri = n;
                while (le + 1 != ri) {
                    ll mid = (le+ri)/2;
                    if (a[mid][r] > c)
                        ri = mid;
                    else
                        le = mid;
                }
                minn = max(minn, ri);
            }
        }
        if (minn <= maxx && !off)
            cout << minn+1;
        else
            cout << -1;
        cout << '\n';
    }
}
