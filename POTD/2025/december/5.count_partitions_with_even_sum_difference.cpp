class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0, ans = 0, n = nums.size() - 1;
        for(int i = 0; i < n; i++) {
            curr += nums[i];
            if(abs(sum - 2 * curr) % 2 == 0) ans++;
        }
        return ans;
    }
};