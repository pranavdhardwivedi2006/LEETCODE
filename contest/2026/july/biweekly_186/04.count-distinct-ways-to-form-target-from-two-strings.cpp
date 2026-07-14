class Solution {
int dp[101][101][101][2][2], n1, n2, n3, MOD = 1e9 + 7;
int rec(int idx1, int idx2, int idx3, bool taken1, bool taken2, string& s1, string& s2, string& target) {
    if(idx3 >= n3) return (taken1 && taken2);
    if(idx1 >= n1 && idx2 >= n2) return 0;
    if(dp[idx1][idx2][idx3][taken1][taken2] != -1) return dp[idx1][idx2][idx3][taken1][taken2];
    long long ans = 0;
    for(int i = idx1; i < n1; i++) {
        if(s1[i] == target[idx3]) ans += rec(i + 1, idx2, idx3 + 1, true, taken2, s1, s2, target);
    }
    for(int j = idx2; j < n2; j++) {
        if(s2[j] == target[idx3]) ans += rec(idx1, j + 1, idx3 + 1, taken1, true, s1, s2, target);
    }
    return dp[idx1][idx2][idx3][taken1][taken2] = ans % MOD;
}
public:
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp, -1, sizeof(dp));
        n1 = word1.size(); n2 = word2.size(); n3 = target.size();
        return rec(0, 0, 0, false, false, word1, word2, target);
    }
};