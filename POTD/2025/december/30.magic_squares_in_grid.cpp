class Solution {
private:
    int row(vector<vector<int>>& grid, int i, int j) {
        return grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    }
    int col(vector<vector<int>>& grid, int i, int j) {
        return grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
    }
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        int arr[10] = {0}; int sum = row(grid, i, j);
        for(int x = i; x < i + 3; x++) {
            for(int y = j; y < j + 3; y++) {
                if(grid[x][y] > 9 || arr[grid[x][y]] > 0) return false;
                if(grid[x][y] == 0) return false;
                arr[grid[x][y]]++;
            }
        }
        if (sum == col(grid, i, j) && 
            sum == row(grid, i + 1, j) &&
            sum == row(grid, i + 2, j) &&
            sum == col(grid, i, j + 1) &&
            sum == col(grid, i, j + 2) &&
            sum == grid[i][j] + grid[i+2][j+2] + grid[i+1][j+1] &&
            sum == grid[i+2][j] + grid[i][j+2] + grid[i+1][j+1]) return true;
        return false;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 2 >= n || j + 2 >= m) continue;
                isValid(grid, i, j) ? ans++ : 0;
            }
        }
        return ans;
    }
};