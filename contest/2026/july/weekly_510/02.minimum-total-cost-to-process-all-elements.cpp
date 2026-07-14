class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long ans = 0, p = k;
        int MOD = 1e9 + 7;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= p) p -= nums[i];
            else {
                long long x = (1LL * nums[i] - p + k - 1) / k;
                ans += x;
                p += x * k;
                p -= nums[i];
            }
        }
        long long first = ans;
        long long second = ans + 1;
        if(first % 2 == 0) first /= 2;
        else second /= 2;
        return 1LL * (first % MOD) * (second % MOD) % MOD;
    }
};