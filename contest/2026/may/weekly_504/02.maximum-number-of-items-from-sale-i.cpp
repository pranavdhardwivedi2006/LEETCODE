class Solution {
vector<int> free;
vector<vector<int>> dp;
int cheapest = INT_MAX;
int rec(int index, int budget, vector<vector<int>>& items) {
    int n = items.size();
    if(index >= n) return budget / cheapest;
    if(!budget) return 0;
    if(dp[index][budget] != -1) return dp[index][budget];
    int leave = rec(index + 1, budget, items);
    int take = 0;
    if(items[index][1] <= budget) {
        take = free[index] + rec(index + 1, budget - items[index][1], items);
    }
    return dp[index][budget] = max(take, leave);
}
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), cnt = 0; 
        free.resize(n); dp.resize(n, vector<int>(budget + 1, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(items[j][0] % items[i][0] == 0) cnt++;
            }
            free[i] = cnt; cnt = 0;
            cheapest = min(cheapest, items[i][1]);
        }
        return rec(0, budget, items);
    }
};