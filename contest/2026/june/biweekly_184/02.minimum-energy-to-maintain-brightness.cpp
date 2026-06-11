class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bulbs = brightness / 3 + (brightness % 3 ? 1 : 0);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++) {
            if(merged.empty() || merged.back()[1] < intervals[i][0]) merged.push_back(intervals[i]);
            else merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
        long long ans = 0;
        for(auto& it : merged) ans += it[1] - it[0] + 1;
        return ans * bulbs;
    }
};