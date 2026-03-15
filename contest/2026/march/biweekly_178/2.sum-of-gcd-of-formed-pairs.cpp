class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = 0;
        for(auto& it : nums) {
            maxi = max(maxi, it);
            it = gcd(maxi, it);
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while(l < r) ans += gcd(nums[l++], nums[r--]);
        return ans;
    }
};