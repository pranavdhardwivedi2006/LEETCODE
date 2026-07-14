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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans; ans.reserve(queries.size());
        int l = 0, r = 0;
        DisjointSet ds(n);
        while(r < n) {
            if(nums[r] - nums[l] > maxDiff) { l++; continue; }
            ds.unionByRank(l, r++);
        }
        for(auto& it : queries) {
            if(ds.findUPar(it[0]) == ds.findUPar(it[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};