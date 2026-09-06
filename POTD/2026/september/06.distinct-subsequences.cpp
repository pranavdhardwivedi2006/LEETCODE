class Solution {
vector<vector<int>> dp;
private:
    int rec(int idx, int idx2, string& s, string& t) {
        if(idx < 0 || idx2 < 0) return 0;
        if(dp[idx][idx2] != -1) return dp[idx][idx2];
        int leave = rec(idx - 1, idx2, s, t);
        int take = 0, x = 0; if(idx2 == 0) x = 1;
        if(s[idx] == t[idx2]) take = x + rec(idx - 1, idx2 - 1, s, t);
        return dp[idx][idx2] = take + leave;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        dp.resize(n, vector<int>(m, -1));
        return rec(n - 1, m - 1, s, t);
    }
};