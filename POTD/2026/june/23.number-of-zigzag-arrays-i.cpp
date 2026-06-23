class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        r -= l; int MOD = 1e9 + 7;
        vector<array<int, 2>> dp(r + 3, {1, 1}), temp(r + 3);
        for(int j = 1; j < n; j++) {
            for(auto& it : temp) it[0] = it[1] = 0;
            for(int i = 1; i < r + 2; i++) {
                temp[0][1] = (temp[0][1] + dp[i][0]) % MOD;
                temp[i][1] = (temp[i][1] - dp[i][0] + MOD) % MOD;
                temp[i+1][0] = (temp[i+1][0] + dp[i][1]) % MOD;
            }
            long long curr1 = 0, curr2 = 0;
            for(int i = 0; i < r + 2; i++) {
                dp[i][0] = curr1 = (curr1 + temp[i][0]) % MOD;
                dp[i][1] = curr2 = (curr2 + temp[i][1]) % MOD;
            }
        }
        long long ans = 0;
        for(int i = 1; i < r + 2; i++) {
            ans = (ans + dp[i][0] + dp[i][1]) % MOD;
        }
        return ans;
    }
};