class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& it : nums) it = abs(it);
        sort(nums.begin(), nums.end());
        long long ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i < n / 2) ans -= 1LL * nums[i] * nums[i];
            else ans += 1LL * nums[i] * nums[i];
        }
        return ans;
    }
};