class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0, n = nums.size(), prev = INT_MIN;
        while(i < n && prev < nums[i]) prev = nums[i++];
        if(i == n || i == 1) return false;
        while(i < n && prev > nums[i]) prev = nums[i++];
        if(i == n) return false;
        while(i < n && prev < nums[i]) prev = nums[i++];
        if(i == n) return true;
        return false;
    }
};