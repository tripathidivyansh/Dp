#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int solve(vector<int>& height, int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return abs(height[1] - height[0]);
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int firstS = solve(height, n - 1, dp) + abs(height[n] - height[n - 1]);
        int secondS = solve(height, n - 2, dp) + abs(height[n] - height[n - 2]);

        dp[n] = min(firstS, secondS);
        return dp[n];
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return solve(height, n - 1, dp);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the stones:\n";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int result = sol.minCost(height);
    cout << "Minimum energy required to reach the last stone: " << result << endl;

    return 0;
}
