#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<int>& chosen) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));


    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {

                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }


    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen.push_back(i);
            w -= wt[i - 1];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: " <<endl ;
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter values of items: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items: " << endl ;
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter maximum capacity of knapsack: " << endl ;
    cin >> W;

    vector<int> chosen;
    int maxValue = knapsack(W, wt, val, n, chosen);

    cout << "Maximum value in knapsack = " << maxValue << endl;
    cout << "Items picked (1-based index): " <<endl ;
    for (int i = chosen.size() - 1; i >= 0; i--) {
        cout << chosen[i] << " ";
    }
    cout << endl;

    return 0;
}
