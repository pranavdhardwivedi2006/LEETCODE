class Solution {
public:
    long long elevatorRequests(int m, int start, vector<vector<int>>& requests) {
        int n = requests.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, LLONG_MAX));
        for(int i = 0; i < n; i++) dp[1<<i][i] = max(abs(start - requests[i][1]), requests[i][0]);
        for(int i = 2; i < (1 << n); i++) {
            if(!((i - 1) & i)) continue;
            for(int j = 0; j < n; j++) {
                int p = 1 << j;
                if(!(p & i)) continue;
                p = i ^ p;
                for(int k = 0; k < n; k++) {
                    if(dp[p][k] == LLONG_MAX) continue;
                    long long reachTime = abs(requests[k][1] - requests[j][1]) + dp[p][k];
                    dp[i][j] = min(dp[i][j], max(reachTime, 1LL * requests[j][0]));
                }
            }
        }
        long long ans = LLONG_MAX;
        for(auto it : dp[(1 << n) - 1]) {
            ans = min(ans, it);
        }
        return ans;
    }
};