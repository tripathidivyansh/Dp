#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive + Memoization function
int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i >= n || j >= m) {
        return INT_MAX;
    }
    if (i == n - 1 && j == m - 1) {
        return grid[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int right = solve(i + 1, j, n, m, grid, dp);
    int bottom = solve(i, j + 1, n, m, grid, dp);

    dp[i][j] = grid[i][j] + min(right, bottom);
    return dp[i][j];
}

int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid values:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int result = solve(0, 0, n, m, grid, dp);
    cout << "Minimum path sum: " << result << endl;

    return 0;
}
