class Solution {
vector<vector<bool>> vis;
char next(int n, char c) {
    if(n == 3) return c == 'l' ? 'u' : 'r';
    if(n == 4) return c == 'r' ? 'u' : 'l';
    if(n == 5) return c == 'l' ? 'd' : 'r';
    if(n == 6) return c == 'r' ? 'd' : 'l';
    return c;
}
bool check(int x, int y, char c, vector<vector<int>>& grid) {
    int n = grid[x][y];
    if(c == 'l' && (n == 1 || n == 3 || n == 5)) return true;
    if(c == 'r' && (n == 1 || n == 4 || n == 6)) return true;
    if(c == 'u' && (n == 2 || n == 5 || n == 6)) return true;
    if(c == 'd' && (n == 2 || n == 3 || n == 4)) return true;
    return false;
}
bool rec(int x, int y, char c, vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    bool check = this -> check(x, y, c, grid);
    if(!check) return false;
    if(x == n - 1 && y == m - 1) return true;
    if(vis[x][y]) return false; vis[x][y] = true;
    char next = this -> next(grid[x][y], c);
    int nx = x, ny = y;
    if(next == 'r') ny--;
    if(next == 'l') ny++;
    if(next == 'd') nx--;
    if(next == 'u') nx++;
    return rec(nx, ny, next, grid);
}
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vis.resize(grid.size(), vector<bool>(grid[0].size()));
        int n = grid[0][0]; char c;
        if(n == 1 || n == 3) return rec(0, 0, 'l', grid);
        if(n == 2 || n == 6) return rec(0, 0, 'u', grid);
        if(n == 4) {
            bool ans = rec(0, 0, 'd', grid);
            for(auto& it : vis) fill(it.begin(), it.end(), false);
            return ans || rec(0, 0, 'r', grid);
        }
        bool ans = rec(0, 0, 'l', grid);
        for(auto& it : vis) fill(it.begin(), it.end(), false);
        return ans || rec(0, 0, 'u', grid);
    }
};