// Calculate the minimum number of coins needed
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int count_min_Combinations(vector<int> coin, int n, int target)
{
    vector<vector<int>> dp(n+1, vector<int>(target + 1, INT_MAX));

    // base case: 0 coins needed to make sum 0
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // fill the table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= target; j++)
        {
            // Using the current coin (if coin value <= j)
            if(coin[i-1] <= j)
            {
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coin[i-1]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

int main()
{
    int n, target;
    cout << "Enter the number of coins: " << endl;
    cin >> n;

    vector<int> coin(n);
    cout << "Enter the coins: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    cout << "Enter the amount: ";
    cin >> target;

    cout << "Minimum number of coins required: "
         << count_min_Combinations(coin, n, target) << endl;

    return 0;
}
