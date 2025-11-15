#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<vector<int>>> dp;
int n, m;
private:
    int calc(vector<vector<int>>& grid, int k, int x, int y) {
        if(k < 0) return INT_MIN;
        if(x == n - 1 && y == m - 1) return 0;
        if(dp[x][y][k] != -1) return dp[x][y][k];
        int right = INT_MIN, down = INT_MIN;
        if(y + 1 < m) {
            int cost = grid[x][y+1] == 2 ? 1 : grid[x][y+1];
            int p = calc(grid, k - cost, x, y + 1);
            right = p == INT_MIN ? p : grid[x][y+1] + p;
        }
        if(x + 1 < n) {
            int cost = grid[x+1][y] == 2 ? 1 : grid[x+1][y];
            int p = calc(grid, k - cost, x + 1, y);
            down = p == INT_MIN ? p : grid[x+1][y] + p;
        }
        return dp[x][y][k] = max(down, right);
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(); m = grid[0].size(); k = min(k, 400);
        dp.resize(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int ans = calc(grid, k, 0, 0);
        return ans == INT_MIN ? -1 : ans;
    }
};