class Solution {
int n, m;
vector<vector<int>> dp;
private:
    bool rec(string& s, string& p, int idx1, int idx2) {
        if(idx1 < 0 && idx2 < 0) return true;
        if(idx1 >= 0 && idx2 < 0) return false;
        if(idx1 < 0 && idx2 >= 0) return p[idx2] == '*' ? rec(s, p, idx1, idx2 - 1) : false;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        bool flag = false;
        if(s[idx1] == p[idx2] || p[idx2] == '?') flag = rec(s, p, idx1 - 1, idx2 - 1);
        else if(p[idx2] == '*') {
            flag = rec(s, p, idx1, idx2 - 1); 
            flag |= rec(s, p, idx1 - 1, idx2);
        }
        return dp[idx1][idx2] = flag;
    }
public:
    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        dp.resize(n, vector<int>(m, -1));
        return rec(s, p, n - 1, m - 1);
    }
};