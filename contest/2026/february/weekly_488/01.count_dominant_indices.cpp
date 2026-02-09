class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n - 1; i++) {
            sum -= nums[i];
            if(nums[i] > (sum / (n - i - 1))) ans++;
        }
        return ans;
    }
};