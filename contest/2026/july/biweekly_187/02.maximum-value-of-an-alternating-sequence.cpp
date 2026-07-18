class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans = s;
        ans += 1LL * n / 2 * m;
        ans -= (n - 1) / 2;
        if((n & 1) && n != 1) ans++;
        return ans;
    }
};