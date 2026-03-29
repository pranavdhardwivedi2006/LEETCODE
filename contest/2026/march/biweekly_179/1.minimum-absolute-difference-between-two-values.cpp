class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = 1e9, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] == 1 && nums[j] == 2) ans = min(ans, j - i);
                if(nums[i] == 2 && nums[j] == 1) ans = min(ans, j - i);
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};