class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> trk(maxi, 0);
        for(auto it : nums) trk[it]++;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(trk[nums[i]]) {
                for(int j = nums[i]; j < maxi; j += nums[i]) {
                    if(trk[j]) {
                        ans += 1LL * nums[i] * trk[j];
                        trk[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};