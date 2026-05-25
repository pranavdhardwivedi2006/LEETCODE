class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int sum = 0, taken = 0;
            for(int j = 0; j < m; j++) {
                taken++;
                sum += grid[i][j];
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if(taken > 1) ans = max(ans, sum);
                }
                else ans = max(ans, sum);
                if(sum < 0) sum = taken = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            int sum = 0, taken = 0;
            for(int j = 0; j < n; j++) {
                taken++;
                sum += grid[j][i];
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if(taken > 1) ans = max(ans, sum);
                }
                else ans = max(ans, sum);
                if(sum < 0) sum = taken = 0;
            }
        }
        for(int j = 0; j < m; j++) {
            if(j) {
                ans = max(ans, grid[0][j] + grid[0][j-1]);
                ans = max(ans, grid[n-1][j] + grid[n-1][j-1]);
            }
            ans = max(ans, grid[0][j] + grid[1][j]);
            ans = max(ans, grid[n-2][j] + grid[n-1][j]);
        }
        for(int i = 0; i < n; i++) {
            if(i) {
                ans = max(ans, grid[i][0] + grid[i-1][0]);
                ans = max(ans, grid[i][m-1] + grid[i-1][m-1]);
            }
            ans = max(ans, grid[i][0] + grid[i][1]);
            ans = max(ans, grid[i][m-2] + grid[i][m-1]);
        }
        return ans;
    }
};