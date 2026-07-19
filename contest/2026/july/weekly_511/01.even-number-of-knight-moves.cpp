class Solution {
int dp[8][8][4];
int dx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[8] = {-1, 1, -1, 1, -2, -2, 2, 2};
int rec(int steps, int x, int y, int tx, int ty) {
    if(x < 0 || x > 7 || y < 0 || y > 7) return 0;
    if(x == tx && y == ty) return !(steps & 1);
    if(dp[x][y][(steps&1)+2] != -1) return false;
    dp[x][y][(steps&1)+2] = false;
    if(dp[x][y][steps&1] != -1) return dp[x][y][steps&1];
    bool ans = false;
    for(int i = 0; i < 8; i++) {
        int x_ = x + dx[i], y_ = y + dy[i];
        ans |= rec(steps + 1, x_, y_, tx, ty);
    }
    return dp[x][y][steps&1] = ans;
}
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        memset(dp, -1, sizeof(dp));
        return rec(0, start[0], start[1], target[0], target[1]);
    }
};