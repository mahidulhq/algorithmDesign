#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LCS(string x1, string x2) {
    int n = x1.length();
    int m = x2.length();


    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x1[i - 1] == x2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    string lcs_str = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (x1[i - 1] == x2[j - 1]) {
            lcs_str = x1[i - 1] + lcs_str;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS Length: " << dp[n][m] << endl;
    cout << "LCS String: " << lcs_str << endl;
}

int main() {
    string x1, x2;
    cout << "Enter first string: " << endl;
    cin >> x1;
    cout << "Enter second string: " << endl;
    cin >> x2;

    LCS(x1, x2);
    return 0;
}
