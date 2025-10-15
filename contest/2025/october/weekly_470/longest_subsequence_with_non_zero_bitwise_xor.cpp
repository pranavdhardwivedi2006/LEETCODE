class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[n-1] == 0) return 0;
        for(int i = 0; i < n; i++) xr ^= nums[i];
        return xr ? n : n - 1;
    }
};