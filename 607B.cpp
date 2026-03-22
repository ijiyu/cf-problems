#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int dp[500][500];
int a[500];

int main() {
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 501;
    
    for (int i = 0; i < 500; i++)
        dp[i][i] = 1;

    for (int length = 0; length < n; length++) {
        for (int start = 0; start < n-length; start++) {
            for (int i = start; i < start+length; i++) {
                int end = start+length;
                if (a[start] == a[end])
                    dp[start][end] = min(dp[start][end], dp[start][i] + dp[i+1][end] - 1);
                dp[start][end] = min(dp[start][end], dp[start][i]+dp[i+1][end]);
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << dp[0][n-1];
}
