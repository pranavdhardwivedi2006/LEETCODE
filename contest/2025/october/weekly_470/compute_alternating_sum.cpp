class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i += 2) {
            sum += nums[i];
            if(i + 1 < n) sum -= nums[i+1];
        }
        return sum;
    }
};