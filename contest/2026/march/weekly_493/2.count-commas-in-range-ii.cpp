class Solution {
public:
    long long countCommas(long long n) {
        long long x = 0, ans = 0;
        while(x <= n) {
            x = x * 10 + 9;
            x = x * 10 + 9;
            x = x * 10 + 9;
            ans += max(n - x, 0LL);
        }
        return ans;
    }
};