class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> prefix(n), suffix(n);
        for(int i = 0; i < n; i++) {
            prefix[i] = nums[i];
            suffix[n-i-1] = nums[n-i-1];
            if(i) {
                prefix[i] = max(prefix[i], prefix[i-1]);
                suffix[n-i-1] = max(suffix[n-i-1], suffix[n-i]);
            }
        }
        for(int i = 0; i + k < n; i++) {
            ans = max(ans, prefix[i] + suffix[i+k]);
        }
        return ans;
    }
};