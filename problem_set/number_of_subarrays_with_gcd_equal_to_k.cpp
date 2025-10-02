class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            int gc = nums[i];
            for(int j = i; j < n; j++) {
                gc = gcd(gc, nums[j]);
                if(gc == k) ans++;
                if(gc < k) break;
            }
        }
        return ans;
    }
};