//Calculate the number of coin change combinations
#include <bits/stdc++.h>
using namespace std;

int countCombinations(vector<int>& coin, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: 1 way to make sum 0 (choose no coin)
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    // Build the table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= target; j++)
        {
            // Without using current coin
            dp[i][j] = dp[i - 1][j];

            // Using current coin (if coin value <= j)
            if(coin[i - 1] <= j)
            {
                dp[i][j] += dp[i][j - coin[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main()
{
    int n, target;   // n = number of coins, amount = target
    cout << "Enter the number of coins:" << endl;
    cin >> n;

    vector<int> coin(n);
    cout << "Enter the coins:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    cout << "Enter the amount:" << endl;
    cin >> target;

    cout << "Total combinations: "
         << countCombinations(coin, n, target) << endl;

    return 0;
}
