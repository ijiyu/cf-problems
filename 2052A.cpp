#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> c(n);
    vector<int> ind(n+1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ind[c[i]] = i;
    }
    int out = 0;
    vector<pair<int, int>> outs;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            out++;
            outs.push_back({j, i});
            if (ind[i] < ind[j]) {
                out++;
                outs.push_back({i, j});
            }
        }
    }
    cout << out << endl;
    for (auto &[i, j] : outs)
        cout << i << " " << j << '\n';
}
