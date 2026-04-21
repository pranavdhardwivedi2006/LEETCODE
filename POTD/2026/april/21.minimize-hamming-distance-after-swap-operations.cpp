class DisjointSet {
vector<int> parent, rank;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = target.size();
        DisjointSet dsu(n);
        for(auto& it : allowedSwaps) {
            dsu.unionByRank(it[0], it[1]);
        }
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> mpp;
        for(int i = 0; i < n; i++) {
            int par = dsu.findUPar(i);
            int s = source[i], t = target[i];
            if(mpp[par][s] < 0) ans++;
            mpp[par][s]++;
            if(mpp[par][t] > 0) ans++;
            mpp[par][t]--;
        }
        return n - ans;
    }
};