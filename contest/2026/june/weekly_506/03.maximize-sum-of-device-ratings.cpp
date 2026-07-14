class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size(), m = units[0].size();
        for(auto& it : units) sort(it.begin(), it.end());
        long long ans = 0, sum = 0, mini = INT_MAX;
        if(m == 1) {
            for(auto& it : units) sum += it[0];
            return sum;
        } else {
            for(auto& it : units) {
                sum += it[1];
                mini = min(mini, 1LL * it[0]);
            }     
        }
        sum += mini;
        for(auto& it : units) {
            ans = max(ans, sum - it[1]);
        }
        return ans;
    }
};