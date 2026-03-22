#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p) cin >> i;
    string x;
    cin >> x;
    bool possible = true;
    int first, last;
    for (int i = 0; i < n; i++) {
        if (x[0] == '1' || x[n-1] == '1' ||
                (p[i] == 1 && x[i] == '1') || (p[i] == n && x[i] == '1')) {
            possible = false;
            break;
        }
        if (p[i] == 1)
            first = i;
        else if (p[i] == n)
            last = i;
    }
    if (!possible) {
        cout << -1 << '\n';
        return;
    }
    first++;
    last++;
    if (first > last) {
        int t = first;
        first = last;
        last = t;
    }
    cout << "5\n";
    cout << 1 << " " << first << '\n';
    cout << 1 << " " << last << '\n';
    cout << first << " " << last << '\n';
    cout << first << " " << n << '\n';
    cout << last << " " << n << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
