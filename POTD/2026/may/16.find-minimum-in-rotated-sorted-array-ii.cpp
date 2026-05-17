class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, min = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            min = std::min(min, nums[mid]);
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++; 
                r--;
            } else if (nums[mid] <= nums[r]) {
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return min;
    }
};