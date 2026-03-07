class Solution {
public:
    int concatenatedBinary(int n) {
        long long x = 1, ans = 0;
        int MOD = 1e9 + 7;
        for(int i = n; i > 0; i--) {
            int k = i;
            while(k) {
               ans = (ans + (k & 1) * x) % MOD;
               x = x * 2 % MOD;
               k >>= 1;
            }
        }
        return ans;
    }
};