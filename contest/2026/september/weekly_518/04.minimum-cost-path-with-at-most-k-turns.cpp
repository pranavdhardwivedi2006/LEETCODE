class Solution {
// l -> 0, u -> 1, r -> 2, d -> 3
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<vector<long long>>>> dp(4, vector<vector<vector<long long>>>(n, vector<vector<long long>>(m, vector<long long>(k + 1, LLONG_MAX))));
        priority_queue<tuple<long long, int, int, int, int>, vector<tuple<long long, int, int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0, k, 0});
        pq.push({grid[0][0], 0, 0, k, 1});
        dp[0][0][0][k] = grid[0][0];
        while(!pq.empty()) {
            auto [cost, x, y, remain, prev] = pq.top(); pq.pop();
            if(x == n - 1 && y == m - 1) return cost;
            for(int i = 0; i < 4; i++) {
                int p = x + dx[i], q = y + dy[i];
                if(p < 0 || p >= n || q < 0 || q >= m) continue;
                int turns = (i == prev) ? remain : remain - 1;
                if(turns < 0) continue;
                if(dp[i][p][q][turns] > cost + grid[p][q]) {
                    dp[i][p][q][turns] = cost + grid[p][q];
                    pq.push({cost + grid[p][q], p, q, turns, i});
                }
            }
        }
        return -1;
    }
};