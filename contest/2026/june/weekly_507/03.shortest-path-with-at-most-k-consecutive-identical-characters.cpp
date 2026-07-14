class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dp(n, vector<int>(51, INT_MAX));
        vector<vector<pair<int, int>>> adj(n);
        for(auto& it : edges) adj[it[0]].push_back({it[1], it[2]});
        using t = tuple<int, int, int>;
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({0, 0, 1});
        while(!pq.empty()) {
            auto [wt, node, x] = pq.top(); pq.pop();
            if(x > k || dp[node][x] <= wt) continue;
            dp[node][x] = wt;
            for(auto& [u, v] : adj[node]) {
                if(labels[node] == labels[u]) pq.push({wt + v, u, x + 1});
                else pq.push({wt + v, u, 1});
            }
        }
        int ans = *min_element(dp[n-1].begin(), dp[n-1].end());
        if(ans == INT_MAX) return -1;
        return ans;
    }
};