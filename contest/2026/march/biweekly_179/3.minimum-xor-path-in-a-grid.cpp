class Solution {
vector<vector<vector<int>>> dp; int n, m;
void rec(int i, int j, int curr, vector<vector<int>>& grid) {
    if(i >= n || j >= m) return ;
    if(i == n - 1 && j == m - 1) {
        dp[i][j][curr] = curr ^ grid[i][j];
        return ;
    }
    if(dp[i][j][curr] != -1) return ;
    dp[i][j][curr] = curr ^ grid[i][j];
    rec(i + 1, j, dp[i][j][curr], grid);
    rec(i, j + 1, dp[i][j][curr], grid);
}
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(2000, -1)));
        rec(0, 0, 0, grid); int mini = INT_MAX;
        for(int i = 0; i < 2000; i++) {
            if(dp[n-1][m-1][i] != -1) mini = min(mini, dp[n-1][m-1][i]);
        }
        return mini;
    }
};