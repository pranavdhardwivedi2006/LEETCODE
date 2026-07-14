class Solution {
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0]) health--;
        using t = vector<int>;
        vector<t> vis(n, t(m, 0));
        queue<tuple<int, int, int>> q;
        if(health) q.push({health, 0, 0});
        while(!q.empty()) {
            auto [h, i, j] = q.front(); q.pop();
            if(i == n - 1 && j == m - 1) return true;
            for(int p = 0; p < 4; p++) {
                int x = dx[p] + i;
                int y = dy[p] + j;
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                int k = h - grid[x][y];
                if(!k || k <= vis[x][y]) continue;
                vis[x][y] = k;
                q.push({k, x, y});
            }
        }
        return false;
    }
};