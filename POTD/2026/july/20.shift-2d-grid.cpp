class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), i = 0, s = n * m;
        vector<int> temp(s);
        for(auto& it : grid) {
            for(auto& x : it) temp[i++] = x;
        }
        k %= s; k = (s - k) % s;
        for(auto& it : grid) {
            for(auto& x : it) x = temp[k++%s];
        }
        return grid;
    }
};