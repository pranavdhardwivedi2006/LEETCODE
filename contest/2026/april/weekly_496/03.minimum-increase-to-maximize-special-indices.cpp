class Solution {
long long rec(int index, int n, int take, int cnt, vector<int>& nums, vector<array<long long, 2>>& dp) {
    if(cnt == 0) return 0;
    if(index == n - 2) {
        return take ? max(max(nums[index-1], nums[index+1]) - nums[index] + 1, 0) : 0;
    }
    if(dp[index][take] != -1) return dp[index][take];
    long long cost = max(max(nums[index-1], nums[index+1]) - nums[index] + 1, 0);
    cost += rec(index + 2, n, take, cnt - 1, nums, dp);
    long long cost2 = LLONG_MAX;
    if(!take) cost2 = rec(index + 1, n, 1, cnt, nums, dp);
    return dp[index][take] = min(cost, cost2);
}
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if((n - 2) & 1) {
            long long ans = 0;
            for(int i = 1; i < n - 1; i += 2) {
                if(max(nums[i-1], nums[i+1]) >= nums[i])
                ans += max(nums[i-1], nums[i+1]) - nums[i] + 1;
            }
            return ans;            
        }
        vector<array<long long, 2>> dp(n, {-1, -1});
        int cnt = (n - 2) / 2 + (n - 2) % 2;
        return rec(1, n, 0, cnt, nums, dp);
    }
};