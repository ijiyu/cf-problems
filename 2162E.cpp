#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> left;
    for (int i = 1; i <= n; i++)
        left.insert(i);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (left.find(a[i]) != left.end())
            left.erase(left.find(a[i]));
    }

    if (left.size() == 0) {
        for (int i = 0; i < k; i++)
            cout << a[i%3] << " ";
        cout << endl;
    }
    else {
        vector<int> cycle = {*left.begin(), 0, a[n-1]};
        for (int i = 1; i <= n; i++) {
            if (i != cycle[0] && i != cycle[2]) {
                cycle[1] = i;
                break;
            }
        }
        for (int i = 0; i < k; i++)
            cout << cycle[i%3] << " ";
        cout << endl;
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
