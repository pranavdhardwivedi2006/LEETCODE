class Solution {
int tar;
vector<vector<pair<int, int>>> adj;

bool isPossible(int node, vector<bool>& vis) {
    if(node == tar) return true;
    if(vis[node]) return false;
    vis[node] = true;
    for(auto it : adj[node]) {
        if(isPossible(it.first, vis)) return true;
    }
    return false;
}

bool dfs(int node, int k, int th, vector<vector<pair<int, bool>>>& vis) {
    if(k < 0) return false;
    if(node == tar) return true;
    if(vis[node][k].first != -1) return vis[node][k].first;
    if(vis[node][k].second == true) return false;
    vis[node][k].second = true;
    for(auto [u, v] : adj[node]) {
        bool ans = false;
        if(v > th) ans = dfs(u, k - 1, th, vis);
        else ans = dfs(u, k, th, vis);
        if(ans) return true;
    }
    return vis[node][k].first = false;
}
    
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        adj.resize(n);
        tar = target; 
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<bool> visi(n);
        if(!isPossible(source, visi)) return -1; 
        int l = 0, r = 1e9 + 1;
        vector<vector<pair<int, bool>>> vis(n, vector<pair<int, bool>>(k + 1, {-1, false}));
        while(l <= r) {
            int mid = l + (r - l) / 2;
            for(auto& it : vis) for(auto& x : it) x = {-1, false};
            bool possible = dfs(source, k, mid, vis);
            if(possible) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};