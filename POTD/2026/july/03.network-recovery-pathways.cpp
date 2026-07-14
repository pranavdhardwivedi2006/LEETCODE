class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for(auto& it : edges) {
            if(online[it[0]] && online[it[1]]) adj[it[0]].push_back({it[1], it[2]});
        }
        int l = 0, r = 1e9;
        vector<long long> vis(n, 1e18);
        while(l <= r) {
            int mid = l + (r - l) / 2;
            fill(vis.begin(), vis.end(), 1e18);
            using t = pair<long long, int>;
            priority_queue<t, vector<t>, greater<t>> pq;
            pq.push({0, 0});
            bool possible = false;
            while(!pq.empty()) {
                auto [cost, node] = pq.top(); pq.pop();
                if(cost > k) continue;
                if(vis[node] <= cost) continue;
                vis[node] = cost;
                if(node == n - 1) {possible = true; break;}
                for(auto& [neigh, wt] : adj[node]) {
                    if(wt < mid) continue;
                    pq.push({cost + wt, neigh});
                }
            }
            if(possible) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};