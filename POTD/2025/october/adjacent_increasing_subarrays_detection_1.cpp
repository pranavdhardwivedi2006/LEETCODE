class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        vector<int> ans;
        while(i < n) {
            int x = 0, prev = -1001;
            while(i < n && prev < nums[i]) {
                prev = nums[i];
                x++, i++;
            }
            ans.push_back(x);
        }
        n = ans.size();
        for(int i = 0; i < n; i++) {
            if(ans[i] >= 2 * k || (i < n - 1 && ans[i] >= k && ans[i+1] >= k)) return true;
        }
        return false;
    }
};