class Solution {
vector<vector<int>> dp; 
int n, MOD = 1e9 + 7;
private:
    int rec(vector<pair<int, int>>& arr, int idx, int sum, int l, int r) {
        if(sum > r || idx >= n) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        long long ans = rec(arr, idx + 1, sum, l, r);
        auto [u, v] = arr[idx];
        for(int i = 1; i <= v; i++) {
            if(sum + i * u > r) break;
            if(sum + i * u >= l) ans += 1 + rec(arr, idx + 1, sum + i * u, l, r);
            else ans += rec(arr, idx + 1, sum + i * u, l, r);
        }
        return dp[idx][sum] = ans % MOD;
    }
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<pair<int, int>> arr;
        arr.push_back({nums[0], 0});
        for(auto& it : nums) {
            if(it > r) continue;
            if(arr.back().first == it) arr.back().second++;
            else arr.push_back({it, 1});
        }
        n = arr.size();
        dp.resize(n, vector<int>(sum + 1, -1));
        return rec(arr, 0, 0, l, r) + !l;
    }
};