#include <iostream>
#include <vector>
using namespace std;

bool solve(int index, vector<int>& arr, int target, vector<vector<int>>& dp) {
    if (target < 0) return false;
    if (target == 0) return true;
    if (index >= arr.size()) return false;

    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    bool include = false;
    if (target >= arr[index]) {
        include = solve(index + 1, arr, target - arr[index], dp);
    }

    bool exclude = solve(index + 1, arr, target, dp);
    dp[index][target] = include || exclude;

    return dp[index][target];
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    bool result = solve(0, arr, target, dp);

    if (result)
        cout << "Subset with given sum exists." << endl;
    else
        cout << "No subset with given sum." << endl;

    return 0;
}
