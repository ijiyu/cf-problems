#include <bits/stdc++.h>
using namespace std;

bool work(int m, int n, int k, int x, vector<int> &a) {
    a[0] = -m;
    a[n-1] = x + m;
    int out = 0;
    for (int i = 1; i < n; i++)
        out += max((a[i] - m) - (a[i-1] + m) + 1, 0);
    return out >= k;
}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    a.push_back(INT_MIN);
    a.push_back(INT_MAX);
    sort(a.begin(), a.end());
    n += 2;
    int l = 0;
    int r = x + 1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (work(m, n, k, x, a)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    a[0] = -l;
    a[n-1] = x + l;
    int j = 0;
    for (int i = 1; i < n; i++)
        for (j = max(j, a[i - 1] + l); j <= min((a[i] - l), x) && k; j++)
            cout << j << ' ', k--;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
