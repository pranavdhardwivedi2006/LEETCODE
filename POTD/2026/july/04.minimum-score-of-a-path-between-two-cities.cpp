class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        using t = pair<int, int>; int ans = 1e6;
        vector<vector<t>> adj(n + 1);
        for(auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        queue<t> q;
        q.push({100000, 1});
        vector<int> vis(n + 1, 1000000);
        while(!q.empty()) {
            auto [mini, node] = q.front(); q.pop();
            if(node == n) ans = min(ans, mini);
            if(vis[node] <= mini) continue;
            vis[node] = mini;
            for(auto& it : adj[node]) {
                q.push({min(mini, it.second), it.first});
            }
        }
        return ans;
    }
};