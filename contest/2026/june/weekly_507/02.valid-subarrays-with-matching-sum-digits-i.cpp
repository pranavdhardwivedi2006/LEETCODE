class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            long long sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                int k = log10(sum);
                long long p = pow(10, k);
                if(p > sum) p /= 10;
                if(sum % 10 == x && sum / p == x) ans++;
            } 
        }
        return ans;
    }
};