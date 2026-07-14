class Solution {
int dp[201][201][201], MOD = 1e9 + 7;
int rec(int index, int g1, int g2, vector<int>& nums) {
    if(index >= nums.size()) return !g1 && g1 == g2;
    if(dp[index][g1][g2] != -1) return dp[index][g1][g2];
    long long ans = 0;
    int x1 = gcd(g1, nums[index]), x2 = gcd(g2, nums[index]);
    ans += (g1 == x2) + rec(index + 1, g1, x2, nums);
    ans += (x1 == g2) + rec(index + 1, x1, g2, nums);
    ans += rec(index + 1, g1, g2, nums);
    return dp[index][g1][g2] = ans % MOD;
}
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, nums) - 1;
    }
};