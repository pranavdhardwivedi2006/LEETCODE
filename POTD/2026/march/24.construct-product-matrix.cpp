class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int prev = 1, n = grid.size(), m = grid[0].size(), MOD = 12345, k;
        vector<vector<int>> pre(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pre[i][j] = prev;
                prev = 1LL * prev * grid[i][j] % MOD;
            }
        } prev = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                k = grid[i][j];
                grid[i][j] = 1LL * pre[i][j] * prev % MOD;
                prev = 1LL * prev * k % MOD;
            }
        }
        return grid;
    }
};