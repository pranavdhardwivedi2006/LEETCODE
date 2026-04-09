class Solution {
int MOD = 1e9 + 7;

int power(int x, int y) {
    if(y == 0) return 1;
    long long mult = power(x, y / 2);
    mult = mult * mult % MOD;
    if(y & 1) mult = mult * x % MOD;
    return mult;
}

void process(int k, vector<int>& nums, vector<vector<int>>& query) {
    int n = nums.size(), off = query[0][0] % k; 
    vector<int> coff(n / k + 2, 1);
    for(auto& it : query) {
        int l = it[0] / k;
        int r = l + (it[1] - it[0]) / k + 1;
        coff[l] = 1LL * coff[l] * it[2] % MOD;
        coff[r] = 1LL * coff[r] * power(it[2], MOD - 2) % MOD;
    }
    long long multiplier = 1; 
    for(int i = 0; off < n; i++) {
        multiplier = multiplier * coff[i] % MOD;
        nums[off] = nums[off] * multiplier % MOD;
        off += k;
    }
}

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        map<pair<int, int>, vector<vector<int>>> mpp;
        int n = nums.size(); int sq = sqrt(n);
        for(auto& it : queries) {
            if(it[2] >= sq) {
                for(int i = it[0]; i <= it[1]; i += it[2]) {
                    nums[i] = 1LL * it[3] * nums[i] % MOD;
                }
            }
            else mpp[{it[0] % it[2], it[2]}].push_back({it[0], it[1], it[3]});
        }
        for(auto& [u, v] : mpp) process(u.second, nums, v);
        int ans = 0; for(auto& it : nums) ans ^= it;
        return ans;
    }
};