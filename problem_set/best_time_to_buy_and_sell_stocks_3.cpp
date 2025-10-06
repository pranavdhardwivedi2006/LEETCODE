class Solution {
private:
    int rec(vector<int>& arr, vector<vector<vector<int>>>& dp, int idx, int trans, bool buy) {
        int n = arr.size(), ans = 0;
        if(trans == 2 || idx == n) return 0;
        if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];
        if(buy) {
            ans = max(ans, rec(arr, dp, idx + 1, trans, !buy) - arr[idx]); 
            ans = max(ans, rec(arr, dp, idx + 1, trans, buy)); 
        }
        else {
            ans = max(ans, arr[idx] + rec(arr, dp, idx + 1, trans + 1, !buy)); 
            ans = max(ans, rec(arr, dp, idx + 1, trans, buy)); 
        }
        return dp[idx][buy][trans] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return rec(prices, dp, 0, 0, true);
    }
};