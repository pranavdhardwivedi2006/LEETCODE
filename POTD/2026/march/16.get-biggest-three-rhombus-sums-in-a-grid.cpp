class Solution {
set<int> st;

int up(int i, int j, int k, vector<vector<int>>& grid) {
    if(k < 0) return 0;
    return grid[i][j] + up(i - 1, j + 1, k - 1, grid);
}

int down(int i, int j, int k, vector<vector<int>>& grid) {
    if(k < 0) return 0;
    return grid[i][j] + down(i + 1, j + 1, k - 1, grid);
}

void find(int k, vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    for(int i = k; i + k < n; i++) {
        for(int j = 0; j + 2 * (k + 1) - 2 < m; j++) {
            int curr = up(i, j, k - 1, grid);
            curr += down(i + 1, j + 1, k - 2, grid);
            curr += down(i - k, j + k, k, grid);
            curr += up(i + k, j + k, k - 1, grid);
            st.insert(curr);
        }
    }
}

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        for(int i = 0; i < 26; i++) find(i, grid);
        vector<int> ans;
        while(ans.size() < 3 && !st.empty()) {
            ans.push_back(*st.rbegin());
            st.erase(--st.end());
        }
        return ans;
    }
};