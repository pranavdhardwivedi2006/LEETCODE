class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0}); 
        sort(restrictions.begin(), restrictions.end());
        int ans = 0, k = restrictions.size();
        vector<int> rest(k);
        for(int i = 1; i < k; i++) {
            rest[i] = min(restrictions[i][1], rest[i-1] + restrictions[i][0] - restrictions[i-1][0]);
        }
        for(int i = k - 2; i >= 0; i--) {
            rest[i] = min(rest[i], rest[i+1] + restrictions[i+1][0] - restrictions[i][0]);
        }
        for(int i = 1; i < k; i++) {
            int height = (restrictions[i][0] - restrictions[i-1][0] + rest[i] + rest[i-1]) / 2;
            ans = max(ans, height);
        }
        return max(ans, rest.back() + n - restrictions.back()[0]);
    }
};