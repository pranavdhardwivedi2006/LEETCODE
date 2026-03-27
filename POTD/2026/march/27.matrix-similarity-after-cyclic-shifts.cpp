class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k %= m; if (k == 0) return true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i % 2 == 0) {
                    if(mat[i][j] != mat[i][(j + k) % m]) return false;
                } 
                else if(mat[i][j] != mat[i][(j + m - k) % m]) return false;
            }
        }
        return true;
    }
};