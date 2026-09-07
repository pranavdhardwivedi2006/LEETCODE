class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7, n = s.size();
        vector<int> dp(n + 1), trk(26, -1);
        dp[0] = 1; 
        for(int i = 0; i < n; i++) {
            long long curr = dp[i] * 2LL;
            int k = trk[s[i]-'a'];
            if(k != -1) curr = curr + MOD - dp[k];
            dp[i+1] = curr % MOD;
            trk[s[i]-'a'] = i;
        }
        return ((dp[n] - 1) % MOD + MOD) % MOD;
    }
};