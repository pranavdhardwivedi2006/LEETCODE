class Solution {
long long power(int x, int y, int MOD) {
    if(y == 0) return 1;
    long long prod = power(x, y / 2, MOD);
    prod = prod * prod % MOD;
    if(y & 1) prod = prod * x % MOD;
    return prod;
}
bool rabinKarp(int k, vector<int>& nums) {
    int n = nums.size();
    map<pair<int, int>, int> mpp;
    long long hash1 = 0, hash2 = 0;
    int MOD1 = 1e9 + 7, MOD2 = 911382323;
    long long k1 = power(n, k - 1, MOD1);
    long long k2 = power(n, k - 1, MOD2);
    for(int i = 0; i < k; i++) {
        hash1 = (hash1 + power(n, k - i - 1, MOD1) * nums[i] % MOD1) % MOD1;
        hash2 = (hash2 + power(n, k - i - 1, MOD2) * nums[i] % MOD2) % MOD2;
    }
    mpp[{hash1, hash2}]++;
    for(int i = k; i < n; i++) {
        hash1 = ((hash1 + MOD1 - nums[i-k] * k1 % MOD1) * n % MOD1 + nums[i]) % MOD1;
        hash2 = ((hash2 + MOD2 - nums[i-k] * k2 % MOD2) * n % MOD2 + nums[i]) % MOD2;
        mpp[{hash1, hash2}]++;
    }
    for(auto& [u, v] : mpp) if(v == 1) return true;
    return false;
}
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            bool possible = rabinKarp(mid, nums);
            if(possible) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};