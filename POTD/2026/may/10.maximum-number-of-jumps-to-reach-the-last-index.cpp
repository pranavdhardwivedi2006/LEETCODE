class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(n, -1); ans[n-1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(ans[j] != -1 && abs(nums[i] - nums[j]) <= target) {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }
        return ans[0];
    }
};