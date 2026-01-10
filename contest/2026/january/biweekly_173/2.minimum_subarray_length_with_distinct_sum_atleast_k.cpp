class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        map<int, int> mpp;
        int l = 0, r = 0, n = nums.size();
        int sum = 0, ans = INT_MAX;
        while(r < n) {
            while(r < n && sum < k) {
                if(mpp.find(nums[r]) == mpp.end()) sum += nums[r];
                mpp[nums[r++]]++;
            }
            if(sum >= k) ans = min(ans, r - l);
            while(l <= r && sum >= k) {
                if(sum >= k) ans = min(ans, r - l);
                int k = mpp[nums[l]]--;
                if(k == 1) {
                    sum -= nums[l];
                    mpp.erase(nums[l]);
                } l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};