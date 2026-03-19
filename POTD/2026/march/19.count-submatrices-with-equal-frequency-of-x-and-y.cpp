class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<array<int, 2>>> count(n, vector<array<int, 2>>(m, {0, 0})); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') count[i][j][0]++;
                if(grid[i][j] == 'Y') count[i][j][1]++;
                count[i][j][0] += i ? count[i-1][j][0] : 0;
                count[i][j][1] += i ? count[i-1][j][1] : 0;
                count[i][j][0] += j ? count[i][j-1][0] : 0;
                count[i][j][1] += j ? count[i][j-1][1] : 0;
                count[i][j][0] -= (i && j) ? count[i-1][j-1][0] : 0;
                count[i][j][1] -= (i && j) ? count[i-1][j-1][1] : 0;
                if(count[i][j][0] && count[i][j][0] == count[i][j][1]) ans++;
            }
        }
        return ans;
    }
};