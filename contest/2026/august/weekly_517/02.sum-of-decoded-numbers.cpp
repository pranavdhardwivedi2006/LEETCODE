class Solution {
int MOD = 1e9 + 7;
long long power(long long x, long long y) {
    if(y == 0) return 1;
    long long prod = power(x, y / 2);
    prod = prod * prod % MOD;
    if(y & 1) prod = prod * x % MOD;
    return prod;
}
public:
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(auto it : nums) {
            long long curr = 0;
            int w = it % 10;
            long long d = it / 10;
            string s = to_string(d);
            long long x = stoll(s.substr(0, w));
            long long y = stoll(s.substr(w));
            ans = (ans + power(x, y)) % MOD;
        }
        return ans;
    }
};