class Solution {
vector<vector<long long>> dp;
long long rec(bool canTake, int index, vector<int>& nums, string& s) {
    if(index >= s.size()) return 0;
    if(dp[index][canTake] != -1) return dp[index][canTake];
    long long ans = canTake ? nums[index] : 0;
    long long take = rec(s[index] == '1', index + 1, nums, s);
    long long leave = rec(false, index + 1, nums, s);
    if(!canTake && s[index] == '1') leave += nums[index];
    return dp[index][canTake] = ans + max(take, leave);
}
public:
    long long maxTotal(vector<int>& nums, string s) {
        reverse(s.begin(), s.end());
        reverse(nums.begin(), nums.end());
        int n = s.size();
        dp.resize(n, vector<long long>(2, -1));
        return rec(false, 0, nums, s);
    }
};