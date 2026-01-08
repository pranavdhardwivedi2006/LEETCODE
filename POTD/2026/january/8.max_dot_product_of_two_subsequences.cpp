class Solution {
int n, m;
vector<vector<int>> dp;
private:
    int rec(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i >= n || j >= m) return -1e8;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = max(rec(i + 1, j, nums1, nums2), rec(i, j + 1, nums1, nums2));
        maxi = max(maxi, nums1[i] * nums2[j] + rec(i + 1, j + 1, nums1, nums2));
        return dp[i][j] = max(maxi, nums1[i] * nums2[j]);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(); m = nums2.size();
        dp.resize(n, vector<int>(m, -1));
        return rec(0, 0, nums1, nums2);
    }
}; 