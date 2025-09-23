class Solution {
int parent = -1;
private:
    int rec(vector<int>& edges, vector<bool>& vis, int idx) {
        int n = vis.size();
        if(edges[idx] == -1) return 0;
        if(vis[idx]) {
            parent = edges[idx]; 
            return 1;
        }
        vis[idx] = true;
        int ans = rec(edges, vis, edges[idx]);
        if(parent != -1) ans++;
        if(parent == idx) parent = -1;
        return ans;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            int k = rec(edges, vis, i);
            if(parent == -1) ans = max(ans, k);
            parent = -1;
        }
        return ans ? ans : -1;
    }
}; 