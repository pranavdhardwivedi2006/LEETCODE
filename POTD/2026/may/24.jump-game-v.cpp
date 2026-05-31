class Solution {
int rec(int index, int d, vector<int>& arr, vector<int>& dp) {
    if(dp[index] != -1) return dp[index];
    int n = arr.size(), ans = 1;
    for(int i = index + 1; i <= min(n - 1, index + d); i++) {
        if(arr[i] >= arr[index]) break;
        ans = max(ans, 1 + rec(i, d, arr, dp));
    }
    for(int i = index - 1; i >= max(0, index - d); i--) {
        if(arr[i] >= arr[index]) break;
        ans = max(ans, 1 + rec(i, d, arr, dp));
    }
    return dp[index] = ans;
}
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++) {
            rec(i, d, arr, dp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};