class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][100] = {0};
        dp[0][0] = poured;
        for(int i = 0; i < 99; i++) {
            for(int j = 0; j <= i; j++) {
                double extra = (dp[i][j] - 1) / 2;
                if(extra < 0) continue ;
                dp[i][j] = 1;
                dp[i+1][j] += extra;
                dp[i+1][j+1] += extra;
            }
        }
        for(int i = 0; i < 100; i++) dp[99][i] = min(1.00, dp[99][i]);
        return dp[query_row][query_glass];
    }
};