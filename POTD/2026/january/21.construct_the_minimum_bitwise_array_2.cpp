class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) {
                int k = nums[i], cnt = 0;
                while(k & 1) {
                    cnt++; k >>= 1;
                } 
                ans[i] = nums[i] - (1 << --cnt);
            }
        }
        return ans;
    }
};