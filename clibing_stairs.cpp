#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    int ways = sol.climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;
    return 0;
}
