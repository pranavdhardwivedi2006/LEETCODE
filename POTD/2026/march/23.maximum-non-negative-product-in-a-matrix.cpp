class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), MOD = 1e9 + 7;
        vector<vector<array<long long, 2>>> dp(n, vector<array<long long, 2>>(m, {0, 0}));
        dp[0][0][0] = dp[0][0][1] = grid[0][0];
        for(int i = 1; i < n; i++) dp[i][0][0] = dp[i][0][1] = grid[i][0] * dp[i-1][0][0];
        for(int j = 1; j < m; j++) dp[0][j][0] = dp[0][j][1] = grid[0][j] * dp[0][j-1][0];
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j][0] = max({dp[i-1][j][0], dp[i-1][j][1], dp[i][j-1][0], dp[i][j-1][1]}) * grid[i][j];
                dp[i][j][1] = min({dp[i-1][j][0], dp[i-1][j][1], dp[i][j-1][0], dp[i][j-1][1]}) * grid[i][j];
            }
        }
        long long ans = max({dp[n-1][m-1][0], dp[n-1][m-1][1], -1LL});
        return ans == -1 ? ans : ans % MOD;
    }
};