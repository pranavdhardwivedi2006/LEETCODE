class Solution {
vector<vector<bool>> vis;
int dx[4] = {1, -1, 0, 0}, n;
int dy[4] = {0, 0, 1, -1}, m;
bool rec(int x, int y, int px, int py, char c, vector<vector<char>>& grid) {
    if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] != c) return false;
    if(vis[x][y]) return true;
    vis[x][y] = true;
    for(int i = 0; i < 4; i++) {
        if(x + dx[i] == px && y + dy[i] == py) continue;
        if(rec(x + dx[i], y + dy[i], x, y, c, grid)) return true;
    }
    return false;
}
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j]) continue;
                if(rec(i, j, -1, -1, grid[i][j], grid)) return true;
            }
        }
        return false;
    }
};