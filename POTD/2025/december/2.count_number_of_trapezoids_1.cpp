class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int, greater<int>> mpp;
        for(auto& it : points) mpp[it[1]]++;
        long long sum = 0, ans = 0, MOD = 1e9 + 7;
        for(auto& [_, v] : mpp) {
            long long x = 1LL * v * (v - 1) / 2 % MOD * sum % MOD;
            ans = (ans + x) % MOD; sum += 1LL * v * (v - 1) / 2 % MOD; 
        }
        return ans;
    }
};