#include <iostream>
#include <vector>
using namespace std;

// Recursive + memoized function
int solve(int index, int end, vector<int>& nums, vector<int>& dp) {
    if (index > end) return 0;
    if (dp[index] != -1) return dp[index];

    int include = nums[index] + solve(index + 2, end, nums, dp);
    int exclude = solve(index + 1, end, nums, dp);

    return dp[index] = max(include, exclude);
}

// Rob function for circular houses
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> dp1(n + 1, -1);
    vector<int> dp2(n + 1, -1);

    int case1 = solve(0, n - 2, nums, dp1); // Exclude last house
    int case2 = solve(1, n - 1, nums, dp2); // Exclude first house

    return max(case1, case2);
}

int main() {
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the amount of money in each house:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int maxMoney = rob(nums);
    cout << "Maximum amount that can be robbed: " << maxMoney << endl;

    return 0;
}
