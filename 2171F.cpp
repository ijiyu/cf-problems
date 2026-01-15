#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &i : p)
        cin >> i;
    vector<int> pre(n);
    pre[0] = p[0];
    for (int i = 1; i < n; i++)
        pre[i] = min(p[i], pre[i-1]);
    vector<int> suf(n);
    suf[n-1] = p[n-1];
    vector<int> s;
    s.push_back(n-1);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(p[i], suf[i+1]);
        if (i > 0) {
            if (suf[i] < pre[i-1]) {
                cout << "No\n";
                return;
            }
        }
        if (p[i] > suf[i+1])
            s.push_back(i);
    }
    if (pre[n-2] > suf[n-1])  {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    s.push_back(-1);
    cout << endl;
    for (int index = 0; index < s.size() - 1; index++) {
        for (int i = s[index]-1; i > s[index+1]; i--)
            cout << p[i] << " " << p[s[index]] << '\n';
    }
    for (int index = 0; index < s.size() - 2; index++) {
        cout << pre[s[index+1]-1] << ' ' << p[s[index]] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
