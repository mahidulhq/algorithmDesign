#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[1005][1005];
int lcs(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1);
    else
    {
        int op1 = lcs(i - 1, j);
        int op2 = lcs(i, j - 1);
        return dp[i][j] = max(op1, op2);
    }
}
int main()
{
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int n = a.size() - 1;
    int m = b.size() - 1;
    cout << lcs(n, m);
    return 0;
}