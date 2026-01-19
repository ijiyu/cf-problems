#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<bool> seen(n+1, false);

    if (a[n-1] == b[n-1]) {
        cout << n << endl;
        return;
    }

    int ans = -1;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == a[i+1] || b[i] == b[i+1] || seen[a[i]] || seen[b[i]] || a[i] == b[i]) {
            ans = i;
            break;
        }
        seen[a[i+1]] = true;
        seen[b[i+1]] = true;
    }
    cout << ans + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}

