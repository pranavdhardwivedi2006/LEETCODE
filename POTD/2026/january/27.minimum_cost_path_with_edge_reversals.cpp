class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], 2 * it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> cost(n, INT_MAX);
        pq.push({0, 0});
        while(!pq.empty()) {
            auto [u, v] = pq.top(); pq.pop();
            if(v == n - 1) return u;
            for(auto [x, y] : adj[v]) {
                if(cost[x] <= u + y) continue ;
                pq.push({y + u, x});
                cost[x] = u + y;
            }
        }
        return -1;
    }
};