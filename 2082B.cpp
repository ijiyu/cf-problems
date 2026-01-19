#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int floor(int x) {
    return x/2;
}

int ceil(int x) {
    return (x % 2 == 0) ? x/2 : (x+1)/2;
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    int minn = x;
    for (int i = 0; i < n; i++) {
        if (minn == 0)
            break;
        minn = floor(minn);
    }
    for (int i = 0; i < m; i++) {
        if (minn <= 1)
            break;
        minn = ceil(minn);
    }
    int maxx = x;
    for (int i = 0; i < m; i++) {
        if (maxx <= 1)
            break;
        maxx = ceil(maxx);
    }
    for (int i = 0; i < n; i++) {
        if (maxx == 0)
            break;
        maxx = floor(maxx);
    }
    cout << maxx << " " << minn << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
