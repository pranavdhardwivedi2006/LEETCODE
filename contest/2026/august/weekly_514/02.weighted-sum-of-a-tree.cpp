class Solution {
int height = 0;
long long ans = 0;
void rec(int node, int depth, vector<vector<int>>& adj) {
    for(auto it : adj[node]) {
        rec(it, 1 + depth, adj);
    }
    height = max(height, depth);
}
void rec2(int node, int depth, vector<int>& nums, vector<vector<int>>& adj) {
    ans += 1LL * nums[node] * (height - depth + 1);
    for(auto it : adj[node]) {
        rec2(it, depth + 1, nums, adj);
    }
}
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        for(int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }
        rec(0, 1, tree);
        rec2(0, 1, nums, tree);
        return ans;
    }
};