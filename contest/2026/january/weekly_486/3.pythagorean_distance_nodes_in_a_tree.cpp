class Solution {
vector<bool> vis;
private:
    void find(vector<vector<int>>& adj, int node, int curr, vector<int>& d) {
        if(vis[node]) return ;
        vis[node] = true;
        d[node] = curr;
        for(auto it : adj[node]) {
            if(it == node) continue;
            find(adj, it, curr + 1, d);
        }
    }
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        } vis.resize(n, 0);
        vector<int> dist_x(n), dist_y(n), dist_z(n);
        find(adj, x, 0, dist_x); vis.assign(n, 0);
        find(adj, y, 0, dist_y); vis.assign(n, 0);
        find(adj, z, 0, dist_z); 
        vector<long long> arr(3, 0); int ans = 0;
        for(int i = 0; i < n; i++) {
            arr[0] = dist_x[i];
            arr[1] = dist_y[i];
            arr[2] = dist_z[i];
            sort(arr.begin(), arr.end());
            if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) ans++;
        }
        return ans;
    }
};