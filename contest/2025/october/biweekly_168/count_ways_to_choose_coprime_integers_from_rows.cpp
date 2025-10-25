class Solution {
vector<map<int, int>> dp;
int n, m, MOD = 1e9 + 7;
private:
    int rec(vector<vector<int>>& mat, int row, int k) {
        if(row >= n) return k == 1 ? 1 : 0;
        if(dp[row].find(k) != dp[row].end()) return dp[row][k];
        int ways = 0;
        for(int i = 0; i < m; i++) {
            if(row == 0) k = mat[row][i];
            ways = (ways + rec(mat, row + 1, gcd(k, mat[row][i]))) % MOD;
        }
        return dp[row][k] = ways;
    }
public:
    int countCoprime(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        dp.resize(n);
        return rec(mat, 0, 0);
    }
};