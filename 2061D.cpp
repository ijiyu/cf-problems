#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    while (b.size() < a.size()) {
        while (!a.empty() && !b.empty() && *a.begin() == *b.begin()) {
            a.erase(a.begin());
            b.erase(b.begin());
        }
        if (b.empty()) {
            cout << "No\n";
            return;
        }
        if (*b.begin() < *a.begin()) {
            cout << "No\n";
            return;
        }
        int x = *b.begin();
        b.erase(b.begin());
        b.insert(x / 2);
        b.insert((x + 1) / 2);
    }
    while (!a.empty() && !b.empty() && *a.begin() == *b.begin()) {
        a.erase(a.begin());
        b.erase(b.begin());
    }
    cout << (a.empty() && b.empty() ? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
