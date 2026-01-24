class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, max = INT_MIN;
        while (l < r) {
            max = std::max(max, nums[l++] + nums[r--]);
        }
        return max;
    }
};