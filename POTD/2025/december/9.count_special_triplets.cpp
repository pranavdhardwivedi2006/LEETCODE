class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mpp, mpp2;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) mpp2[nums[i]]++;
        for(int i = 0; i < n; i++) {
            mpp2[nums[i]]--;
            ans = (ans + 1LL * mpp[nums[i]*2] * mpp2[nums[i]*2]) % (int)(1e9 + 7);
            mpp[nums[i]]++;
        }
        return ans;
    }
};