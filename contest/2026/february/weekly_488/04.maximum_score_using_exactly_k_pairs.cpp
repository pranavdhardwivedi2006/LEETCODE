class Solution {
long long val = -1e18;
vector<vector<vector<long long>>> dp;
int n, m;
private:
    long long rec(int i, int j, int k, vector<int>& nums1, vector<int>& nums2) {
        if(k <= 0) return 0; if(i >= n || j >= m) return val; 
        if(dp[i][j][k] != LLONG_MIN) return dp[i][j][k];
        long long take = rec(i + 1, j + 1, k - 1, nums1, nums2);
        take += take == val ? 0 : 1LL * nums1[i] * nums2[j];
        long long leave = rec(i + 1, j, k, nums1, nums2);
        leave = max(leave, rec(i, j + 1, k, nums1, nums2));
        return dp[i][j][k] = max(take, leave);
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        n = nums1.size(), m = nums2.size();
        dp.resize(n, vector<vector<long long>>(m, vector<long long>(k + 1, LLONG_MIN)));
        return rec(0, 0, k, nums1, nums2);
    }
};