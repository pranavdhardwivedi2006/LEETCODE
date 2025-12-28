class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size(); int prev = nums[n-1];
        vector<int> mini(n);
        for(int i = n - 1; i >= 0; i--) {
            mini[i] = prev = min(prev, nums[i]);
        }
        long long sum = 0, ans = INT_MIN;
        for(int i = 1; i < n; i++) {
            sum += nums[i-1];
            ans = max(ans, sum - mini[i]);
        }
        return ans;
    } 
};