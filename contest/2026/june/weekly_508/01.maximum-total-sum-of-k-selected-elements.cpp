class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            ans += 1LL * nums[i] * max(mul, 1);
            mul--;
        }
        return ans;
    }
};