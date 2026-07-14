class Solution {
long long rec(int node, int par, vector<vector<int>>& adj, vector<int>& baseTime) {
    if(adj[node].size() == 0) {
        return baseTime[node];
    }
    long long mini = LLONG_MAX, maxi = LLONG_MIN;
    for(auto& it : adj[node]) {
        long long x = rec(it, node, adj, baseTime);
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    return (2 * maxi - mini) + baseTime[node];
}
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for(auto& it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        return rec(0, -1, adj, baseTime);
    }
};