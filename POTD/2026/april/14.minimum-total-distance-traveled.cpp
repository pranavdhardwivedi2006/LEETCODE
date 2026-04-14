class Solution {
long long dp[101][101][101]; int f, r;
long long rec(int idf, int idr, int lim, vector<int>& robot, vector<vector<int>>& factory) {
    if(idf >= f) return idr >= r ? 1e18 : 0;
    if(lim < 0) return 1e18;
    if(idr >= r) return 0;
    if(dp[idf][idr][lim] != -1) return dp[idf][idr][lim];
    long long leave = idf + 1 >= f ? 1e18 : rec(idf + 1, idr, factory[idf+1][1], robot, factory);
    long long take = rec(idf, idr + 1, lim - 1, robot, factory);
    if(take != 1e18) take += abs(robot[idr] - factory[idf][0]);
    return dp[idf][idr][lim] = min(take, leave);
}
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp, -1, sizeof(dp));
        sort(robot.begin(), robot.end()); 
        sort(factory.begin(), factory.end());
        f = factory.size(), r = robot.size();
        return rec(0, 0, factory[0][1], robot, factory);
    }
};