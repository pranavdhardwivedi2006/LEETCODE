class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto& it : grid) for(auto& x : it) if(x < 0) ans++;
        return ans;
    }
};