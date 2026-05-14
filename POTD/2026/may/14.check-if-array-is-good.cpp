class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i-1] != i) return false;
        }
        if(nums[n-1] != n - 1) return false;
        return true;
    } 
};