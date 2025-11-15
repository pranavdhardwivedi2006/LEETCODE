#include<bits/stdc++.h>
using namespace std;

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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DisjointSet ds(c); vector<int> ans;
        for(auto it : connections) ds.unionByRank(it[0], it[1]);
        unordered_map<int, set<int>> mpp;
        for(int i = 1; i <= c; i++) mpp[ds.findUPar(i)].insert(i);
        for(auto it : queries) {
            int k = ds.findUPar(it[1]);
            if(it[0] == 2) mpp[k].erase(it[1]);
            else {
                if(mpp[k].empty()) ans.push_back(-1);
                else if(mpp[k].find(it[1]) != mpp[k].end()) ans.push_back(it[1]);
                else ans.push_back(*mpp[k].begin());
            }
        }  
        return ans;
    }
};