class Solution {
using ll = long long;
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        ll l = 0, r = *max_element(value.begin(), value.end());
        int n = value.size(), MOD = 1e9 + 7; ll ans = 0;
        while(l <= r) {
            ll mid = l + (r - l) / 2;
            ll op = 0;
            for(int i = 0; i < n; i++) {
                if(value[i] > mid) op += (value[i] - mid - 1) / decay[i] + 1;
            }
            if(op <= m) r = mid - 1;
            else l = mid + 1;
        }
        for(int i = 0; i < n; i++) {
            if(value[i] <= l) continue;
            ll k = (value[i] - l - 1) / decay[i] + 1; k %= MOD;
            ans += (k * value[i] - k * (k - 1) / 2 % MOD * decay[i]) % MOD;
            ans %= MOD; m -= k;
        }
        ans = (ans + m * l % MOD) % MOD;
        return ans;
    }
};