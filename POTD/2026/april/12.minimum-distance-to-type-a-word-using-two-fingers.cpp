class Solution {
int dp[27][27][301]; char ref = 'A' - 1;
int dist(char c1, char c2) {
    if(c1 == ref || c2 == ref) return 0;
    int x = (c1 - 'A') / 6 - (c2 - 'A') / 6;
    int y = (c1 - 'A') % 6 - (c2 - 'A') % 6;
    return abs(x) + abs(y);
}
int rec(int idx, char c1, char c2, string& word) {
    int n = word.size(); if(idx >= n) return 0;
    if(dp[c1-ref][c2-ref][idx] != -1) return dp[c1-ref][c2-ref][idx];
    int call1 = dist(c1, word[idx]) + rec(idx + 1, word[idx], c2, word);
    int call2 = dist(c2, word[idx]) + rec(idx + 1, c1, word[idx], word);
    return dp[c1-ref][c2-ref][idx] = min(call1, call2);
}
public:
    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return rec(0, ref, ref, word);
    }
};