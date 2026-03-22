#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int total;

bool work(vector<vector<bool>> &grid) {
    int n = grid.size();
    bool found = false;
    int count = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                if (i < n-1 && j < n-1) {
                    if (grid[i+1][j] && grid[i][j+1] && grid[i+1][j+1])
                        return total == 4;
                }
                bool parity = true;
                int ii = i; int jj = j;
                do {
                    if (grid[ii][jj])
                        count++;
                    ii += parity;
                    jj += !parity;
                    parity = !parity;
                } while (ii < n && jj < n);
                parity = false;
                ii = i; jj = j;
                do {
                    if (grid[ii][jj])
                        count2++;
                    ii += parity;
                    jj += !parity;
                    parity = !parity;
                } while (ii < n && jj < n);
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    return count == total || count2 == total;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));
    total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == '.') ? false : true;
            total += grid[i][j];
        }
    }

    vector<vector<bool>> grid2(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid2[i][j] = grid[n-i-1][j];
    vector<vector<bool>> grid3(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid3[i][j] = grid[i][n-j-1];
    vector<vector<bool>> grid4(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid4[i][j] = grid[n-i-1][n-j-1];
    cout << ((work(grid) || work(grid2) || work(grid3) || work(grid4)) ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
