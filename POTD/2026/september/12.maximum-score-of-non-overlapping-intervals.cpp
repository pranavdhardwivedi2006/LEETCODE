class Solution {
int find(int lower, vector<vector<int>>& arr) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid][1] < lower) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
bool isBetter(long long w1, vector<int>& v1, long long w2, vector<int>& v2) {
    if (w1 != w2) return w1 > w2;
    return v1 < v2;
}
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++) intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<vector<pair<long long, vector<int>>>> dp(n, vector<pair<long long, vector<int>>>(5, {-1LL, {}}));
        for (int i = 0; i < n; i++) {
            int index = find(intervals[i][0], intervals);
            for (int j = 1; j <= 4; j++) {
                long long not_take_wt = i > 0 ? dp[i-1][j].first : -1LL;
                vector<int> not_take_vec = i > 0 ? dp[i-1][j].second : vector<int>();
                long long take_wt = -1LL;
                vector<int> take_vec;
                if (j == 1) {
                    take_wt = intervals[i][2];
                    take_vec = {intervals[i][3]};
                } else if (index >= 0 && dp[index][j-1].first != -1LL) {
                    take_wt = dp[index][j-1].first + intervals[i][2];
                    take_vec = dp[index][j-1].second;
                    take_vec.push_back(intervals[i][3]);
                    sort(take_vec.begin(), take_vec.end());
                }
                if (take_wt == -1LL && not_take_wt == -1LL) {
                    continue; 
                } else if (take_wt == -1LL) {
                    dp[i][j] = {not_take_wt, not_take_vec};
                } else if (not_take_wt == -1LL) {
                    dp[i][j] = {take_wt, take_vec};
                } else {
                    if (isBetter(take_wt, take_vec, not_take_wt, not_take_vec)) {
                        dp[i][j] = {take_wt, take_vec};
                    } else {
                        dp[i][j] = {not_take_wt, not_take_vec};
                    }
                }
            }
        }
        long long maxi = -1LL;
        vector<int> ans;
        for (int j = 1; j <= 4; j++) {
            if (dp[n-1][j].first != -1LL) {
                if (isBetter(dp[n-1][j].first, dp[n-1][j].second, maxi, ans)) {
                    maxi = dp[n-1][j].first;
                    ans = dp[n-1][j].second;
                }
            }
        }
        return ans;
    }
};