class Solution {
int n, m;
vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
private:
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[i][j] = true;        
        for (auto& d : dir) {
            int x = i + d[0], y = j + d[1];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(vis[x][y]) continue;
            if(heights[x][y] < heights[i][j]) continue;
            dfs(x, y, heights, vis);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        for (int j = 0; j < m; j++) dfs(0, j, heights, pacific);
        for (int i = 0; i < n; i++) dfs(i, 0, heights, pacific);
        for (int j = 0; j < m; j++) dfs(n-1, j, heights, atlantic);
        for (int i = 0; i < n; i++) dfs(i, m-1, heights, atlantic);
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};