class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& intervals, int freeStart, int freeEnd) {
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            auto& it = intervals[i];
            if(it[0] >= freeStart && it[1] <= freeEnd) it[0] = it[1] = 1e9 + 7;
            else if(freeStart >= it[0] && freeEnd <= it[1]) {
                intervals.push_back({freeEnd + 1, it[1]});
                intervals[i][1] = freeStart - 1;
            }
            else if(it[0] >= freeStart && it[0] <= freeEnd) it[0] = freeEnd + 1;
            else if(it[1] >= freeStart && it[1] <= freeEnd) it[1] = freeStart - 1;
        }
        for(auto& it : intervals) {
            if(it[0] > it[1]) it[0] = it[1] = 1e9 + 7;
        }
        sort(intervals.begin(), intervals.end());
        while(!intervals.empty() && intervals.back()[0] == 1e9 + 7) intervals.pop_back();
        vector<vector<int>> ans;
        for(auto it : intervals) {
            if(!ans.empty() && ans.back()[1] + 1 >= it[0]) ans.back()[1] = max(ans.back()[1], it[1]);
            else ans.push_back(it);
        }
        return ans;
    }
};