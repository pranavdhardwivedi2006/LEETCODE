class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int l = x, r = x + k - 1;
        while(l < r) {
            for(int i = y; i < y + k; i++) {
                swap(grid[l][i], grid[r][i]);
            }
            l++, r--;
        }
        return grid;
    }
};