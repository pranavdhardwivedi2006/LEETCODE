class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = nums[0], n = nums.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int mini = 1e9;
            for(int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
            }
            if(1LL * maxi - mini <= k) return i;
        }
        return -1;
    }
};