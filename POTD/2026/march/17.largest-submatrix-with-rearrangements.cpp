class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                int cnt = 0;
                while(i < n && matrix[i][j]) matrix[i++][j] = ++cnt;
            }
        }
        for(auto& it : matrix) {
            sort(it.begin(), it.end());
            for(int j = 0; j < m; j++) ans = max(ans, it[j] * (m - j));
        }
        return ans;
    }
};