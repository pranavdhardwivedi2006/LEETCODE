class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int l = 0, s = 0, r = 0;
        int ans = 0, n = nums.size();
        while(s < n) {
            long long pivot = nums[s];
            int cnt = 0;
            long long x = pivot - k, y = pivot + k;
            while(l < s && nums[l] < x) l++; 
            while(r < n && nums[r] <= y) r++;
            while(s < n && nums[s] == pivot) s++, cnt++;
            ans = max(ans, min(r - l - cnt, numOperations) + cnt);
        }
        map<long long, int> mpp;
        for(auto& it : nums) mpp[it]++;
        l = r = 0;
        while(l < n) {
            long long p = 1LL * nums[l] + 2 * k;
            while(r < n && nums[r] <= p) r++;
            long long x = 1LL * nums[l] + k;
            ans = max(ans, min(r - l - mpp[x], numOperations) + mpp[x]);
            l++;
        }
        return ans;
    }
};