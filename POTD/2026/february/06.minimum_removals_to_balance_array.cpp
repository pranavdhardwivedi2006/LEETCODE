class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size();
        int ans = INT_MAX;
        while(r < n) {
            while(r < n && 1LL * nums[l] * k >= nums[r]) r++;
            ans = min(ans, l + n - r);
            l++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};