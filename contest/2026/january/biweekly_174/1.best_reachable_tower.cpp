class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int q = 0; vector<int> ans = {10000000, 10000000};
        int x = center[0], y = center[1];
        for(auto& it : towers) {
            int dist = abs(x - it[0]) + abs(y - it[1]);
            if(dist <= radius && it[2] >= q) {
                if(it[2] > q) ans = {it[0], it[1]};
                else ans = min(ans, {it[0], it[1]});
                q = it[2];
            }
        }
        return ans[0] == 10000000 ? vector<int>({-1, -1}) : ans;
    }
};