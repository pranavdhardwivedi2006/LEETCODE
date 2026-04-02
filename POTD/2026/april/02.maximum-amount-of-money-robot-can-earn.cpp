class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size(), min = -1e9;
        vector<vector<array<int, 3>>> dp(n + 1, vector<array<int, 3>>(m + 1, {min, min, min}));
        dp[1][1][0] = coins[0][0]; if(coins[0][0] < 0) dp[1][1][1] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i == 1 && j == 1) continue;
                dp[i][j][0] = coins[i-1][j-1] + max(dp[i-1][j][0], dp[i][j-1][0]);
                dp[i][j][1] = coins[i-1][j-1] + max(dp[i-1][j][1], dp[i][j-1][1]);
                dp[i][j][1] = max(dp[i][j][1], max(dp[i-1][j][0], dp[i][j-1][0]));
                dp[i][j][2] = coins[i-1][j-1] + max(dp[i-1][j][2], dp[i][j-1][2]);
                dp[i][j][2] = max(dp[i][j][2], max(dp[i-1][j][1], dp[i][j-1][1]));
            }
        }
        return max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    }
};