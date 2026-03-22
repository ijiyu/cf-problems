#include <bits/stdc++.h>
using namespace std;

int dp[502][502];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int j = 0; j <= n; j++) {
        for (int i = 0; i <= n-j; i++) {
            dp[i][i+j] = dp[i+1][i+j]+1;
            for (int k = i+1; k <= i+j; k++) {
                if (s[k] == s[i]) {
                    dp[i][i+j] = min(dp[i][i+j], dp[i+1][k-1] + dp[k+1][i+j]);
                }
            }
        }
    }
    cout << dp[0][n-1];
}
