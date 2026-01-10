class Solution {
int n, m;
vector<vector<int>> dp;
private:
    int calc(string& s, int j) {
        int res = 0, size = s.size();
        while(j < size) res += s[j++];
        return res;
    }
    int rec(string& s1, string& s2, int i, int j) {
        if(i >= n) return calc(s2, j);
        if(j >= m) return calc(s1, i);
        if(dp[i][j] != -1) return dp[i][j];
        int cost = s1[i] + rec(s1, s2, i + 1, j);
        cost = min(cost, s2[j] + rec(s1, s2, i, j + 1));
        if(s1[i] == s2[j]) cost = min(cost, rec(s1, s2, i + 1, j + 1));
        return dp[i][j] = cost;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size(); m = s2.size();
        dp.resize(n, vector<int>(m, -1));
        return rec(s1, s2, 0, 0);
    }
};