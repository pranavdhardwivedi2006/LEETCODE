class Solution {
int n, m;
int dp[252][252];
bool canTake(int prev, int curr, int limit, vector<vector<int>>& grid) {
    if(prev == 251) return true;
    for(int i = 0; i < n; i++) {
        if(abs(grid[i][curr] - grid[i][prev]) > limit) return false;
    }
    return true;
}
int rec(int prev, int curr, int limit, vector<vector<int>>& grid) {
    if(curr >= m) return 0;
    if(dp[prev][curr] != -1) return dp[prev][curr];
    int leave = rec(prev, curr + 1, limit, grid);
    int take = 0;
    if(canTake(prev, curr, limit, grid)) {
        take = 1 + rec(curr, curr + 1, limit, grid);
    }
    return dp[prev][curr] = max(take, leave);
}
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        n = grid.size(); m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return rec(251, 0, limit, grid);
    }
};