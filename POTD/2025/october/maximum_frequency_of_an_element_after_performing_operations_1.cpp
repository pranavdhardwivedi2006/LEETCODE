class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> trk(maxi + 1, 0);
        int l = 0, r = 0, num = 0;
        int ans = 0, n = nums.size();
        for(auto& it : nums) trk[it]++;
        while(num <= maxi) {
            int cnt = 0, x = num - k, y = num + k;
            while(l < n && nums[l] < x) l++; 
            while(r < n && nums[r] <= y) r++;
            ans = max(ans, min(r - l - trk[num], numOperations) + trk[num++]);
        }
        return ans;
    }
};