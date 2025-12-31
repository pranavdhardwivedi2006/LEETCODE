#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<vector<tuple<int, int, bool>>> parent;
public:
    DisjointSet(int n, int m) {
        parent.resize(n, vector<tuple<int, int, bool>>(m));
        for(int i = 0; i < m; i++) parent[0][i] = {0, i, true};
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                parent[i][j] = {i, j, false};
            }
        }
    }

    tuple<int, int, bool> findUPar(int i, int j) {
        auto [u, v, w] = parent[i][j];
        if(u == i && j == v) return parent[i][j];
        return parent[i][j] = findUPar(u, v);
    }

    void uni(int x1, int y1, int x2, int y2) {
        auto [u1, v1, w1] = findUPar(x1, y1);
        auto [u2, v2, w2] = findUPar(x2, y2);
        if(u1 == u2 && v1 == v2) return ;
        if(u1 == u2) {
            if(v1 < v2) parent[u2][v2] = {u1, v1, w1};
            else parent[u1][v1] = {u2, v2, w2};
        }
        else if(u1 < u2) parent[u2][v2] = {u1, v1, w1};
        else parent[u1][v1] = {u2, v2, w2};
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        int n = row * col; DisjointSet ds(row, col);
        for(int i = n - 1; i >= 0; i--) {
            int x = cells[i][0] - 1, y = cells[i][1] - 1; vis[x][y] = 1;
            if(x + 1 < row && vis[x+1][y]) ds.uni(x, y, x + 1, y);
            if(y + 1 < col && vis[x][y+1]) ds.uni(x, y, x, y + 1);
            if(x - 1 >= 0 && vis[x-1][y]) ds.uni(x, y, x - 1, y);
            if(y - 1 >= 0 && vis[x][y-1]) ds.uni(x, y, x, y - 1);
            for(int j = 0; j < col; j++) {
                if(get<2>(ds.findUPar(row - 1, j))) return i;
            }
        }
        return 0;
    }
};