class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for(int &x : nums) total += x;
        int rem = total % p; if(!rem) return 0;
        unordered_map<int, int> mpp; mpp[0] = -1;
        long long sum = 0;
        int n = nums.size(); int ans = n;
        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
            int need = (sum - rem + p) % p;
            if(mpp.count(need)) ans = min(ans, i - mpp[need]);
            mpp[sum] = i;
        }
        return ans == n ? -1 : ans;
    }
};
