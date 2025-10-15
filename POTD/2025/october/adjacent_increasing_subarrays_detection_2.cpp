class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<int> ans;
        while(i < n) {
            int x = 0, prev = -1e9 - 1;
            while(i < n && prev < nums[i]) {
                prev = nums[i];
                x++, i++;
            }
            ans.push_back(x);
        }
        n = ans.size();
        int k = 0;
        for(int i = 0; i < n; i++) {
            k = max(k, ans[i] / 2);
            if(i < n - 1) k = max(k, min(ans[i], ans[i+1]));
        }
        return k;
    }
};
 