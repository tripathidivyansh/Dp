#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int index, vector<int>& coins, int amount, vector<vector<int>>& dp) {
    if (amount == 0) {
        return 0;
    }
    if (index >= coins.size() || amount < 0) {
        return 1e9;
    }
    if (dp[index][amount] != -1) {
        return dp[index][amount];
    }

    int include = 1e9;
    if (amount >= coins[index]) {
        include = 1 + solve(index, coins, amount - coins[index], dp);
    }
    int exclude = solve(index + 1, coins, amount, dp);

    dp[index][amount] = min(include, exclude);
    return dp[index][amount];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int result = solve(0, coins, amount, dp);

    return (result >= 1e9) ? -1 : result;
}

int main() {
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations:\n";
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << "Enter target amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);

    if (result == -1)
        cout << "It is not possible to make up the amount using given coins.\n";
    else
        cout << "Minimum number of coins required: " << result << endl;

    return 0;
}