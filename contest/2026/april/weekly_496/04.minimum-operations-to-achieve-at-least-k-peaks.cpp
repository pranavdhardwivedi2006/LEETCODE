class Solution {
int rec(int index, int k, bool is, vector<int>& nums, vector<vector<int>>& dp) {
    int n = nums.size(); if(k == 0) return 0;
    if(index >= n) return INT_MAX;
    if(index == n - 1 && is) return INT_MAX;
    if(dp[index][k] != -1) return dp[index][k];
    int prev = nums[(n+index-1) % n], next = nums[(index+1) % n];
    if(index == 0) is = true;
    int cost = rec(index + 2, k - 1, is, nums, dp);
    if(cost != INT_MAX) cost += max(max(prev, next) - nums[index] + 1, 0);
    if(index == 0) is = false;
    int cost2 = rec(index + 1, k, is, nums, dp);
    return dp[index][k] = min(cost, cost2);
}
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        int ans = rec(0, k, true, nums, dp);
        dp.assign(n, vector<int>(k + 1, -1));
        ans = min(ans, rec(1, k, false, nums, dp));
        return ans == INT_MAX ? -1 : ans;
    }
};