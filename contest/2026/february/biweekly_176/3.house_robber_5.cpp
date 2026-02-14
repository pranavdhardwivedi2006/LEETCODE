class Solution {
private:
    long long rec(vector<int>& arr, vector<long long>& dp, int idx) {
        int n = arr.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max({rec(arr, dp, idx + 1), rec(arr, dp, idx + 2) + arr[idx]});
    }
    long long house(vector<int>& arr) {
        int n = arr.size();
        vector<long long> dp(n, -1);
        return rec(arr, dp, 0);
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int i = 0, n = nums.size();
        long long ans = 0;
        while(i < n) {
            vector<int> arr;
            int c = colors[i];
            while(i < n && c == colors[i]) arr.push_back(nums[i++]);
            ans += house(arr);
        }
        return ans;
    }
};