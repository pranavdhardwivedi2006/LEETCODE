class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size(), m = classroom[0].size();
        int mpp[20][20];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int k = 0, sx = 0, sy = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(classroom[i][j] == 'S') {
                    sx = i; sy = j;
                }
                if(classroom[i][j] == 'L') {
                    mpp[i][j] = k++;
                } 
            }
        }
        k = 1 << k; k--;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(energy + 1, vector<int>(k + 1, -1))));
        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, 0, energy});
        dp[sx][sy][energy][0] = 0;
        while(!q.empty()) {
            auto [i, j, mask, curr] = q.front(); q.pop();
            int moves = dp[i][j][curr][mask];
            if(mask == k) return moves;
            if(curr == 0) continue;
            for(int p = 0; p < 4; p++) {
                int x = i + dx[p], y = j + dy[p];
                if(x < 0 || y < 0 || x >= n || y >= m || classroom[x][y] == 'X') continue;
                int n_mask = mask, n_energy = curr - 1;
                if(classroom[x][y] == 'L') n_mask = mask | (1 << mpp[x][y]);
                if(classroom[x][y] == 'R') n_energy = energy;
                if(dp[x][y][n_energy][n_mask] == -1) {
                    dp[x][y][n_energy][n_mask] = moves + 1;
                    q.push({x, y, n_mask, n_energy});
                }
            }
        }
        return -1;
    }
};