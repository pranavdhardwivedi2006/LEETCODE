class Solution {
vector<vector<int>> pre;
private:
    bool find(int i, int j, int t, int mid) {
        int sum = 0;
        for(int k = 0; k < mid; k++) {
            sum += pre[i+k][j+mid-1] - (j ? pre[i+k][j-1] : 0);
        }
        return sum <= t;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        pre.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            pre[i][0] = mat[i][0];
            for(int j = 1; j < m; j++) {
                pre[i][j] = pre[i][j-1] + mat[i][j];
            }
        }
        int l = 0, r = min(n, m), ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2; bool is = false;
            for(int i = 0; i + mid <= n; i++) {
                for(int j = 0; j + mid <= m; j++) {
                    if(find(i, j, threshold, mid)) {
                        ans = mid;
                        is = true; goto x;
                    }
                }
            } x : 
            if(is) l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
};