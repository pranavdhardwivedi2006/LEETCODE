class Solution {
void table(vector<vector<int>>& mat, vector<vector<int>>& dp) {
    int n = mat.size(), m = mat[0].size();
    for(int i = n - 1; i >= 0; i--) dp[i][m-1] = mat[i][m-1];
    for(int j = m - 1; j >= 0; j--) dp[n-1][j] = mat[n-1][j];
    for(int i = n - 2; i >= 0; i--) {
        for(int j = m - 2; j >= 0; j--) {
            if(mat[i][j] == 0) continue;
            dp[i][j] = 1;
            dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]}) + 1;
        }
    }
}
void table2(vector<vector<int>>& mat, vector<vector<int>>& dp) {
    int n = mat.size(), m = mat[0].size();
    for(int i = 0; i < n; i++) dp[i][0] = mat[i][0];
    for(int j = 0; j < m; j++) dp[0][j] = mat[0][j];
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(mat[i][j] == 0) continue;
            dp[i][j] = 1;
            dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
        }
    }
}
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        vector<vector<int>> dp2(n, vector<int>(m));
        table(mat, dp2); table2(mat, dp);
        vector<int> a(n), b(n), a1(m), b1(m);
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                maxi = max(maxi, dp[i][j]);
            }
            a[i] = maxi;
        }
        maxi = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < m; j++) {
                maxi = max(maxi, dp2[i][j]);
            }
            b[i] = maxi;
        }
        maxi = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, dp[i][j]);
            }
            a1[j] = maxi;
        }
        maxi = 0;
        for(int j = m - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, dp2[i][j]);
            }
            b1[j] = maxi;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, min(a[i], b[i+1]));
        }
        for(int i = 0; i < m - 1; i++) {
            ans = max(ans, min(a1[i], b1[i+1]));
        }
        return ans * ans;
    }
};