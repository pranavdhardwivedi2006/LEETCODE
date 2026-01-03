class Solution {
vector<vector<vector<vector<int>>>> dp;
int MOD = 1e9 + 7;
private:
    int rec(int c1, int c2, int c3, int row) {
        if(row < 0) return 1;
        if(dp[row][c1][c2][c3] != -1) return dp[row][c1][c2][c3];
        long long ans = 0;
        for(int i = 0; i < 3; i++) {
            if(i == c1) continue;
            for(int j = 0; j < 3; j++) {
                if(i == j || c2 == j) continue;
                for(int k = 0; k < 3; k++) {
                    if(j == k || c3 == k) continue;
                    ans = (ans + rec(i, j, k, row - 1)) % MOD;
                }
            }
        }
        return dp[row][c1][c2][c3] = ans;
    }
public:
    int numOfWays(int n) {
        dp.resize(n, vector<vector<vector<int>>>(
                         3, vector<vector<int>>(3, vector<int>(3, -1))));
        long long ans = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j) continue;
                for(int k = 0; k < 3; k++) {
                    if(j == k) continue;
                    ans = (ans + rec(i, j, k, n - 2)) % MOD;
                }
            }
        }
        return ans;
    }
};