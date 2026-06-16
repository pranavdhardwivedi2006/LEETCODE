class Solution {
    const int MOD = 1e9 + 7;
    vector<int> depth;
    vector<vector<int>> ancestor, adj;
    void generate(int node, int par, int dep) {
        int p = ancestor[node][0] = par;
        depth[node] = dep;

        for(int i = 1; i < 20 && par != -1; i++) {
            ancestor[node][i] = par = ancestor[par][i - 1];
        }
        for(auto it : adj[node]) {
            if(it == p) continue;
            generate(it, node, dep + 1);
        }
    }
    int lift(int node, int k) {
        for(int i = 0; i < 20 && node != -1; i++) {
            if(k & (1 << i))
                node = ancestor[node][i];
        }
        return node;
    }
    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if(u == v) return u;
        for(int i = 19; i >= 0; i--) {
            if(ancestor[u][i] != ancestor[v][i]) {
                u = ancestor[u][i];
                v = ancestor[v][i];
            }
        }
        return ancestor[u][0];
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        adj.resize(n + 1);
        ancestor.resize(n + 1, vector<int>(20, -1));
        depth.resize(n + 1);
        for(auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        generate(1, -1, 0);
        vector<long long> power(n + 1);
        power[0] = 1;
        for(int i = 1; i <= n; i++) {
            power[i] = (power[i-1] * 2) % MOD;
        }
        vector<int> ans;
        for(auto& it : queries) {
            int u = it[0], v = it[1];
            int l = lca(u, v);
            int edges = depth[u] + depth[v] - 2 * depth[l];
            ans.push_back(edges ? power[edges-1] : 0);
        }
        return ans;
    }
};