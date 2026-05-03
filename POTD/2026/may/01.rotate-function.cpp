class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, curr = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            curr += i * nums[i];
        }
        int maxi = curr;
        for(int i = n - 1; i >= 0; i--) {
            curr -= (n - 1) * nums[i];
            curr += sum - nums[i];
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};