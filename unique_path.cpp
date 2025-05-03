#include <iostream>
#include <vector>
using namespace std;

// Recursive + Memoization function
int solve(int m, int n, int& count, int i, int j, vector<vector<int>>& dp) {
    // If out of bounds
    if(i >= m || j >= n) {
        return 0;
    }

    // If we reach the destination
    if(i == m - 1 && j == n - 1) {
        count++;  // Increment count for reaching destination
        return 1;  // Found one unique path
    }

    // If already computed for this cell
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // Move right and down
    int right = solve(m, n, count, i, j + 1, dp);
    int down = solve(m, n, count, i + 1, j, dp); 

    // Store the result in dp
    return dp[i][j] = right + down;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    // Create dp table initialized with -1
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1)); 
    int count = 0;

    // Calculate number of unique paths
    int result = solve(m, n, count, 0, 0, dp);
    
    cout << "Number of unique paths: " << result << endl;
    
    return 0;
}
