class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size(), maxi = 0; 
        int prev = events[n-1][0] + 1;
        map<int, int> mpp;
        for(int i = n - 1; i >= 0; i--) {
            if(events[i][0] != prev) {
                mpp[prev] = maxi;
                prev = events[i][0];
            }
            maxi = max(maxi, events[i][2]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int k = events[i][2];
            auto it = mpp.lower_bound(events[i][1] + 1);
            if(it != mpp.end()) k += it -> second;
            ans = max(ans, k);
        }
        return ans;
    }
};