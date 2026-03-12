class Solution {
static const int MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int z, int o, int limit) {
        vector<vector<vector<int>>> dp(z+1, vector<vector<int>>(o+1, vector<int>(2)));
        for(int i = 1; i <= min(limit, z); i++) dp[i][0][0] = 1;
        for(int i = 1; i <= min(limit, o); i++) dp[0][i][1] = 1;
        for(int i = 1; i <= z; i++) {
            for(int j = 1; j <= o; j++) {
                long long x = i - limit - 1 >= 0 ? dp[i-limit-1][j][1] : 0;
                long long y = j - limit - 1 >= 0 ? dp[i][j-limit-1][0] : 0;
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] - x + MOD) % MOD;
                dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1] - y + MOD) % MOD;
            }
        }
        return (dp[z][o][0] + dp[z][o][1]) % MOD;
    }
};