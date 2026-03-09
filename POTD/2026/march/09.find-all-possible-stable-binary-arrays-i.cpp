class Solution {
vector<vector<vector<vector<int>>>> dp;
int limit, MOD = 1e9 + 7;
private:
    int rec(int z, int o, int c, int l) {
        if(l > limit) return 0;
        if(!z & !o) return 1;
        if(dp[z][o][c][l] != -1) return dp[z][o][c][l];
        long long ans = 0;
        if(!c) {
            if(z) ans = rec(z - 1, o, c, l + 1);
            if(o) ans += rec(z, o - 1, 1, 1);
        } else {
            if(z) ans = rec(z - 1, o, 0, 1);
            if(o) ans += rec(z, o - 1, c, l + 1);
        }
        return dp[z][o][c][l] = ans % MOD;
    } 
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        this -> limit = limit;
        dp.resize(zero + 1, 
            vector<vector<vector<int>>>(one + 1, 
                vector<vector<int>>(2, 
                    vector<int>(limit + 1, -1)
                )
            )
        );
        return rec(zero, one, 0, 0);
    }
};