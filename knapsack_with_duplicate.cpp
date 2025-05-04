#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int solve(int i, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp) {
        // Base case: no items left to process
        if (i >= wt.size()) {
            return 0;
        }

        // Check if the result is already computed
        if (dp[i][capacity] != -1) {
            return dp[i][capacity];
        }

        // Option 1: Exclude the current item
        int ans = solve(i + 1, val, wt, capacity, dp);

        // Option 2: Include the current item, if it fits in the knapsack
        if (wt[i] <= capacity) {
            ans = max(ans, val[i] + solve(i, val, wt, capacity - wt[i], dp)); // Note: we don't increment `i` here for include
        }

        // Store the result in the dp table
        dp[i][capacity] = ans;
        return dp[i][capacity];
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
        return solve(0, val, wt, capacity, dp);
    }
};

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    cout << "Enter weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    Solution sol;
    int result = sol.knapSack(val, wt, capacity);
    
    cout << "Maximum value in Knapsack: " << result << endl;

    return 0;
}
