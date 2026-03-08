class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size(); long long sum = 0;
        vector<long long> pre(n);
        for(int i = 0; i < n; i++) {
            pre[i] = sum; sum += nums[i];
        }
        long long prod = 1;
        int i = n - 1, ans = -1;
        for(; i >= 0; i--) {
            if(prod > pre[i]) break;
            if(prod == pre[i]) ans = i;
            if(prod >= LLONG_MAX / nums[i]) break ;
            prod *= nums[i];
        }
        while(i) {
            if(nums[i] == 0) {prod = 0; break ;}
            i--;
        }
        if(prod == 0 && i) return 0;
        return ans;
    }
};