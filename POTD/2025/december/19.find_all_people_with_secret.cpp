#include <bits/stdc++.h>
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
map<int, unordered_map<int, vector<int>>> mpp;
unordered_set<int> ans;
public:
    void dfs(int u, int time, unordered_set<int>& vis, DisjointSet& ds) {
        if(vis.find(u) != vis.end()) return ; vis.insert(u);
        for(auto& x : mpp[time][u]) {
            ans.insert(x); 
            ds.unionByRank(x, u);
            dfs(x, time, vis, ds);
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointSet ds(n); ds.unionByRank(firstPerson, 0); 
        ans.insert(0); ans.insert(firstPerson);
        for(auto& it : meetings) {
            mpp[it[2]][it[0]].push_back(it[1]);
            mpp[it[2]][it[1]].push_back(it[0]);
        }
        for(auto& it : mpp) {
            int k = ds.findUPar(firstPerson), x = -1;
            unordered_set<int> vis;
            for(auto& [u, v] : it.second) if(ds.findUPar(u) == k) dfs(u, it.first, vis, ds);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};