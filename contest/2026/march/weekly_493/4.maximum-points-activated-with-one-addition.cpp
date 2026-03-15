class Solution {
unordered_map<int, vector<pair<int, int>>> mx, my;
unordered_set<int> stx, sty; vector<bool> vis;

int dfs(int i, vector<vector<int>>& points) {
    bool isx = !stx.count(points[i][0]);
    bool isy = !sty.count(points[i][1]);
    int cnt = vis[i], x = points[i][0], y = points[i][1];
    if(isx) {
        stx.insert(x);
        for(auto& [u, v] : mx[x]) {
            if(vis[v]) continue ;
            vis[v] = true; 
            cnt += dfs(v, points);
        }
    }
    if(isy) {
        sty.insert(y);
        for(auto& [u, v] : my[y]) {
            if(vis[v]) continue ;
            vis[v] = true; 
            cnt += dfs(v, points);
        }
    }
    return cnt;
}
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size(); vis.resize(n, false);
        for(int i = 0; i < n; i++) {
            auto& it = points[i];
            mx[it[0]].push_back({it[1], i});
            my[it[1]].push_back({it[0], i});
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue ;
            stx.clear(); sty.clear();
            int cnt = dfs(i, points);
            ans.push_back(cnt);
        }
        sort(ans.rbegin(), ans.rend());
        if(ans.size() == 1) return ans[0] + 1;
        return ans[0] + ans[1] + 1;
    }
};