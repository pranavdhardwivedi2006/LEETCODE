class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, l1 = 0, r = 1;
        int ans = 2;
        while(r < n - 1) {
            if(1LL * nums[l1] + nums[r] == nums[r+1]) l1++, r++;
            else {
                ans = max(ans, r - l + 1);
                l = l1 = r++;
            }
        }
        ans = max(ans, r - l + 1);
        return ans;
    }
};