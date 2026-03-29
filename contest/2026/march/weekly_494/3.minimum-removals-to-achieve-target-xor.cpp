class Solution {
int rec(int idx, vector<int>& nums, int tar, vector<vector<int>>& dp) {
    int n = dp.size();
    if(idx >= n) {
        if(tar == 0) return 0;
        return -1e9;
    }
    if(dp[idx][tar] != -1) return dp[idx][tar];
    int take = rec(idx + 1, nums, tar ^ nums[idx], dp);
    take += take == -1e9 ? 0 : 1;
    int leave = rec(idx + 1, nums, tar, dp);
    if(tar && take == -1e9 && leave == -1e9) return dp[idx][tar] = -1e9;
    int x = tar == 0 ? 0 : -1e9;
    return dp[idx][tar] = max({take, leave, x});
}
public:
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1e5 + 1, -1));
        int ans = rec(0, nums, target, dp);
        return ans == -1e9 ? -1 : n - ans;
    }
};