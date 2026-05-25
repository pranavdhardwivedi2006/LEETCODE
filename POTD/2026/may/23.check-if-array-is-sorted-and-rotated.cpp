class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i-1] > nums[i]) cnt++; 
        }
        if(cnt == 0) return true;
        if(cnt == 1 && nums[0] >= nums[n-1]) return true;
        return false;
    }
};