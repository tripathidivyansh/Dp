#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive + Memoization approach
int solve(int row, int colm, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if (row == triangle.size() - 1) {
        return triangle[row][colm];
    }
    if (dp[row][colm] != -1) {
        return dp[row][colm];
    }

    int down = triangle[row][colm] + solve(row + 1, colm, triangle, dp);
    int diagonal = triangle[row][colm] + solve(row + 1, colm + 1, triangle, dp);

    return dp[row][colm] = min(down, diagonal);
}

int main() {
    int n;
    cout << "Enter number of rows in triangle: ";
    cin >> n;

    vector<vector<int>> triangle(n);
    cout << "Enter the triangle values row-wise:\n";
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int minTotal = solve(0, 0, triangle, dp);

    cout << "Minimum path sum from top to bottom: " << minTotal << endl;

    return 0;
}
