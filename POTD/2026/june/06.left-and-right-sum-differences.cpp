class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int lsum = 0; vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            rsum -= nums[i];
            ans[i] = abs(rsum - lsum);
            lsum += nums[i];
        }
        return ans;
    }
};