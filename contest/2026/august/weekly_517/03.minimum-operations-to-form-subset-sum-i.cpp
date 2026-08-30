class Solution {
vector<vector<int>> dp;
int rec(int index, int sum, vector<int>& nums) {
    if(sum == 0) return 0;
    if(index >= nums.size() || sum < 0) return INT_MAX;
    if(dp[index][sum] != -1) return dp[index][sum];
    int ans = rec(index + 1, sum, nums);
    int x = nums[index], op = 0;
    while(x) {
        int curr = rec(index + 1, sum - x, nums);
        if(curr != INT_MAX) ans = min(ans, op + curr);
        op++; x /= 2;
    }
    x = nums[index], op = 0;
    while(x <= sum) {
        int curr = rec(index + 1, sum - x, nums);
        if(curr != INT_MAX) ans = min(ans, op + curr);
        op++; x *= 2;
    }
    return dp[index][sum] = ans;
}
public:
    int minOperations(vector<int>& nums, int sum) {
        dp.resize(nums.size(), vector<int>(sum + 1, -1));
        int ans = rec(0, sum, nums);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};