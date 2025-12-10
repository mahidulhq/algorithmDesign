#include<bits/stdc++.h>
using namespace std;

int w[1005],v[1005];
int dp[1005][1005];
int knapsack(int i, int c){
    if(i < 0 || c == 0) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    if(c >= w[i]){
        int op1 = knapsack(i-1 , c - w[i]) + v[i];
        int op2 = knapsack(i-1 ,c);
        return dp[i][c] = max(op1, op2);
    } else return dp[i][c] = knapsack(i-1,c);
}

int main(){
    memset(dp,-1,sizeof(dp));
    int c; cin >> c;
    int n; cin >> n;
    for(int i = 0; i<n;i++) cin >> w[i];
    for(int i = 0; i<n;i++) cin >> v[i];
    
    cout << knapsack(n-1,c);
    return 0;
}