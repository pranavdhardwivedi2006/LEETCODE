class Solution {
private:
int n, m;
vector<vector<int>> dp; 
int rec(vector<string>& strs, int prev, int curr) {
    if(curr >= m) return 0;
    if(dp[prev][curr] != -1) return dp[prev][curr];
    int leave = 1 + rec(strs, prev, curr + 1);
    int take = m; bool check = true;
    for(int i = 0; i < n; i++) {
        if(strs[i][prev] > strs[i][curr]) check = false;
    }
    if(check) take = rec(strs, curr, curr + 1);
    return dp[prev][curr] = min(take, leave);
}
public:
    int minDeletionSize(vector<string>& strs) {
        n = strs.size(); m = strs[0].size();
        dp.resize(m, vector<int>(m, -1));
        int ans = m; 
        for(int i = 0; i < m; i++) ans = min(ans, i + rec(strs, i, i));
        return ans;
    }
};