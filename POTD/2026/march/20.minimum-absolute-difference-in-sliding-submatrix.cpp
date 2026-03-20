class Solution {
private:
    int check(vector<vector<int>>& grid, int row, int col, int k) {
        vector<int> cur;
        for(int i = row; i < row + k; i++) {
            for(int j = col; j < col + k; j++){
                cur.push_back(grid[i][j]);
            }
        }
        sort(cur.begin(), cur.end());
        auto it = std::unique(cur.begin(), cur.end());
        cur.erase(it, cur.end());
        int min = INT_MAX;
        for(int i = 0; i < cur.size() - 1; i++) {
            min = std::min(min, cur[i+1]-cur[i]);
        }
        return INT_MAX == min ? 0 : min;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1);
        for(int i = 0; i < m; i++) {
            if(i + k > m) break;
            for(int j = 0; j < n; j++){
                if(j + k > n) break;
                ans[i].push_back(check(grid, i, j, k));
            }
        }
        return ans;
    }
};