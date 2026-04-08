class Solution {
int MOD = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto& it : queries) {
            for(int i = it[0]; i <= it[1]; i += it[2]) {
                long long k = (1LL * nums[i] * it[3]) % MOD;
                nums[i] = k;
            }
        }
        int xorr = 0;
        for(auto it : nums) xorr ^= it;
        return xorr;
    }
};