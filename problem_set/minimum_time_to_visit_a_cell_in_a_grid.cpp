#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool row = false, col = false;
        if(n == 0 || grid[1][0] - grid[0][0] > 1) row = true;
        if(m == 0 || grid[0][1] - grid[0][0] > 1) col = true;
        if(row && col) return -1;
        vector<vector<int>> trk(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); trk[0][0] = 0;
        while(!pq.empty()) {
            auto [t, it] = pq.top(); pq.pop();
            auto [x, y] = it;
            if(x == n - 1 && y == m - 1) return t; t++;
            if(x + 1 < n) {
                int k = 0;
                if(t < grid[x+1][y]) {
                    k = grid[x+1][y] - t;
                    if(k & 1) k++;
                }
                if(trk[x+1][y] > t + k) {
                    pq.push({t + k, {x + 1, y}});
                    trk[x+1][y] = t + k;
                }
            }
            if(y + 1 < m) {
                int k = 0;
                if(t < grid[x][y+1]) {
                    k = grid[x][y+1] - t;
                    if(k & 1) k++;
                }
                if(trk[x][y+1] > t + k) {
                    trk[x][y+1] = t + k;
                    pq.push({t + k, {x, y + 1}});
                }
            }
            if(x - 1 >= 0) {
                int k = 0;
                if(t < grid[x-1][y]) {
                    k = grid[x-1][y] - t;
                    if(k & 1) k++;
                }
                if(trk[x-1][y] > t + k) {
                    trk[x-1][y] = t + k;
                    pq.push({t + k, {x - 1, y}});
                }
            }
            if(y - 1 >= 0) {
                int k = 0;
                if(t < grid[x][y-1]) {
                    k = grid[x][y-1] - t;
                    if(k & 1) k++;
                }
                if(trk[x][y-1] > t + k) {
                    trk[x][y-1] = t + k;
                    pq.push({t + k, {x, y - 1}});
                }
            }
        }
        return 0;
    }
};