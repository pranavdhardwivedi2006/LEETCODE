class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), k = n / 2, ans = 0;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long curr = 0;
        for(int i = 0; i < k; i++) curr += nums[i];
        if(curr * 2 > sum) ans++;
        for(int i = 0; i < n - 1; i++) {
            curr -= nums[i]; curr += nums[(i+k)%n];
            if(curr * 2 > sum) ans++;
        }
        return ans;
    }
};