#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    multiset<int> suff;
    for (int row = 0; row < n; row++) {
        int ones = 0;
        for (int i = n-1; i >= 0; i--) {
            if (a[row][i] != 1)
                break;
            ones++;
        }
        suff.insert(ones);
    }
    suff.erase(suff.begin());
    suff.insert(0);
    int out = 0;
    for (int mex = 0; mex < n; mex++) {
        if (suff.empty()) break;
        while (*suff.begin() < mex) {
            suff.erase(suff.begin());
            if (suff.empty()) break;
        }
        if (suff.empty()) break;
        if (*suff.begin() < mex) break;
        out++;
        suff.erase(suff.begin());
    }
    cout << out << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
