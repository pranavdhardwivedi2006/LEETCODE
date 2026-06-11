class Solution {
const int MOD = 1e9 + 7;
int power(int b, int e) {
    if(e == 0) return 1;
    long long prod = power(b, e / 2);
    prod = prod * prod % MOD;
    if(e & 1) prod = prod * b % MOD;
    return prod;
}
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for(auto& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        stack<tuple<int, int, int>> st;
        st.push({-1, 1, 0});
        int depth = 0;
        while(!st.empty()) {
            auto [par, node, curr_depth] = st.top(); st.pop();
            depth = max(depth, curr_depth);
            for(auto& it : adj[node]) {
                if(it == par) continue;
                st.push({node, it, curr_depth + 1});
            }
        }
        return power(2, depth - 1);
    }
};