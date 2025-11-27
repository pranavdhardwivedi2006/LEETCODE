class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> arr(k, LLONG_MAX); arr[0] = 0;
        long long ans = LLONG_MIN, sum = 0;
        for(int i = 1; i <= nums.size(); i++) {
            sum += nums[i-1];
            if(i >= k) ans = max(ans, sum - arr[i%k]);
            arr[i%k] = min(sum, arr[i%k]);
        }
        return ans;
    }
};