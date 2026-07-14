class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 1, prev = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= intervals[prev][0] && intervals[i][1] <= intervals[prev][1]) continue;
            if(intervals[i][0] != intervals[prev][0]) ans++; prev = i;
        }
        return ans;
    }
};