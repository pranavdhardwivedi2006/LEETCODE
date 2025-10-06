class Solution {
vector<vector<bool>> vis;
private: 
    void push(int x, int y, int mid, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int n = grid.size();
        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] > mid || vis[x][y]) return ; 
        vis[x][y] = true;
        q.push({x, y});
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0], r = n * n - 1;
        vis.resize(n, vector<bool>(n, false));
        while(l <= r) {
            int mid = (l + r) / 2;
            bool flag = false;
            queue<pair<int, int>> q;
            vis.assign(n, vector<bool>(n, false));
            q.push({0, 0});
            vis[0][0] = true;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                if(x == n - 1 && y == n - 1) {
                    flag = true;
                    break;
                } 
                q.pop();
                push(x-1, y, mid, q, grid);
                push(x+1, y, mid, q, grid);
                push(x, y-1, mid, q, grid);
                push(x, y+1, mid, q, grid);
            }
            if(flag) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};