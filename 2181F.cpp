#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for (int &i : a) {
        cin >> i;
        ones += (i == 1);
    }
    ones += (ones != n);
    cout << ((ones % 2 == 1) ? "Alice" : "Bob") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
