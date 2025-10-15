class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int up = findUPar(u);
        int vp = findUPar(v);
        if (up == vp) return ;
        if(rank[up] < rank[vp]) {
            parent[up] = vp;
        }
        else if(rank[up] > rank[vp]) {
            parent[vp] = up;
        }
        else {
            parent[vp] = up;
            rank[up]++;
        }
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        long long ans = 0; int n = nums.size();
        DisjointSet ds(n-1); 
        for(auto it : swaps) ds.unionByRank(it[0], it[1]);
        unordered_map<int, pair<int, int>> idx;
        unordered_map<int, vector<int>> val;
        for(int i = 0; i < n; i++) {
            int k = ds.findUPar(i);
            if(i & 1) idx[k].second++;
            else idx[k].first++;
            val[k].push_back(nums[i]);
        }
        for(auto& [u, v] : idx) {
            auto& [x, y] = v;
            sort(val[u].begin(), val[u].end());
            for(int i = 0; i < val[u].size(); i++) {
                if(i < y) ans -= val[u][i];
                else ans += val[u][i];
            }
        }
        return ans;
    }
};