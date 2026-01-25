class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int maxi = INT_MAX, i = nums.size() - 1;
        while(i >= 0) {
            if(nums[i] < maxi) {
                maxi = nums[i];
            }
            else return i + 1;
            i--;
        }
        return 0;
    }
};