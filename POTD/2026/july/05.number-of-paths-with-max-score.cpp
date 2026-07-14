class Solution {
int dx[3] = {0, -1, -1};
int dy[3] = {-1, 0, -1};
int MOD = 1e9 + 7;
vector<vector<int>> dp;
vector<vector<vector<int>>> dp2;
int rec(int x, int y, vector<string>& board) {
    if(x == 0 && y == 0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int k = board[x][y] != 'S' ? board[x][y] - '0' : 0;
    int ans = 0, found = false;
    for(int i = 0; i < 3; i++) {
        if(x + dx[i] >= 0 && y + dy[i] >= 0 && board[x+dx[i]][y+dy[i]] != 'X') {
            ans = max(ans, k + rec(x + dx[i], y + dy[i], board));
            found = true;
        }
    }
    if(!found) return dp[x][y] = -1e6;
    return dp[x][y] = ans;
}
int rec2(int x, int y, int remain, vector<string>& board) {
    if(x == 0 && y == 0) return remain == 0;
    if(remain < 0) return 0;
    if(dp2[x][y][remain] != -1) return dp2[x][y][remain];
    int k = board[x][y] != 'S' ? board[x][y] - '0' : 0;
    long long ans = 0;
    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && board[nx][ny] != 'X') {
            ans += rec2(nx, ny, remain - k, board);
        }
    }
    return dp2[x][y][remain] = ans % MOD;
}
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(); cout << n;
        dp.resize(n, vector<int>(n, -1));
        int maxi = rec(n - 1, n - 1, board);
        if(maxi < 0) return {0, 0};
        dp2.resize(n, vector<vector<int>>(n, vector<int>(maxi + 1, -1)));
        int ways = rec2(n - 1, n - 1, maxi, board);
        return {maxi, ways};
    }
};