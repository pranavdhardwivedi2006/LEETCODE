class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n), ans(n);
        int maxi = nums[0], mini = nums[n-1];
        for(int i = 0; i < n; i++) {
            pref[i] = maxi = max(maxi, nums[i]);
        }
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = mini = min(mini, nums[i]);
        }
        ans[n-1] = pref[n-1];
        for(int i = n - 2; i >= 0; i--) {
            if(pref[i] > suff[i+1]) {
                ans[i] = ans[i+1];
            } else {
                ans[i] = pref[i];
            }
        }
        return ans;
    }
};