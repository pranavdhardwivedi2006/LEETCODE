class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<vector<int>> arr(10);
        for(int i = 0; i < nums.size(); i++) {
            int mini = 9, maxi = 0, k = nums[i];
            while(k) {
                int digit = k % 10; k /= 10;
                maxi = max(maxi, digit);
                mini = min(mini, digit);
            }
            arr[maxi-mini].push_back(nums[i]);
        }
        for(int i = 9; i >= 0; i--) {
            if(arr[i].size()) return accumulate(arr[i].begin(), arr[i].end(), 0);
        }
        return -1;
    }
};