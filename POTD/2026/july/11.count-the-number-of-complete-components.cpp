class DisjointSet {
    vector<int> parent, size, edges;
public:
    DisjointSet(int n) {
        size.resize(n, 1);
        edges.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up = findUPar(u);
        int vp = findUPar(v);
        if (up == vp) {edges[up]++; return ;}
        if(size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
            edges[vp] += edges[up] + 1;
        }
        else if(size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
            edges[up] += edges[vp] + 1;
        }
        else {
            parent[vp] = up;
            size[up] += size[vp];
            edges[up] += edges[vp] + 1;
        }
    }

    int countCompleteComponents() {
        int ans = 0;
        for(int i = 0; i < parent.size(); i++) {
            if(parent[i] != i) continue;
            int k = size[i];
            long long edgesRequired = 1LL * k * (k - 1) / 2;
            if(edges[i] == edgesRequired) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto& it : edges) {
            ds.unionBySize(it[0], it[1]);
        }
        return ds.countCompleteComponents();
    }
};