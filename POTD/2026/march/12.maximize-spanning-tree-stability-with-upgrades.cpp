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

struct comp {
    bool operator() (vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        int mini = INT_MAX; DisjointSet ds(n); multiset<int> st;
        for(auto& it : edges) {
            if(it[3]) {
                int par1 = ds.findUPar(it[0]);
                int par2 = ds.findUPar(it[1]);
                if(par1 == par2) return -1;
                ds.unionByRank(it[0], it[1]);
                mini = min(mini, it[2]);
            }
            else pq.push(it);
        }
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int par1 = ds.findUPar(it[0]);
            int par2 = ds.findUPar(it[1]);
            if(par1 == par2) continue ;
            ds.unionByRank(it[0], it[1]);
            st.insert(it[2]);
        }
        while(!st.empty()) {
            auto it = *st.begin(); st.erase(st.begin());
            if(k) it *= 2; mini = min(mini, it); k--;
        }
        int par = ds.findUPar(0);
        for(int i = 1; i < n; i++) if(par != ds.findUPar(i)) return -1;
        return mini;
    }
};