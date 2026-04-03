class Solution {
int n, m; vector<array<int, 2>> dp, arr; 

int find(int left, int right, vector<int>& walls) {
    int l = 0, r = m - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(walls[mid] >= left) r = mid - 1;
        else l = mid + 1;
    }
    int x = l; l = 0, r = m - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(walls[mid] <= right) l = mid + 1;
        else r = mid - 1;
    }
    return max(r - x + 1, 0);
}

int rec(int index, int dir, int prev, vector<int>& walls) {
    if(index >= n) return 0;
    if(dp[index][dir] != -1) return dp[index][dir];
    int lim = index + 1 < n ? arr[index+1][0] - 1 : 1e9;
    int llim = max(prev, arr[index][0] - arr[index][1]);
    int rlim = min(arr[index][0] + arr[index][1], lim);
    int left = find(llim, arr[index][0], walls) + rec(index + 1, 0, arr[index][0] + 1, walls);
    int right = find(arr[index][0], rlim, walls) + rec(index + 1, 1, rlim + 1, walls);
    return dp[index][dir] = max(left, right);
}

public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size(), m = walls.size(); 
        arr.resize(n); dp.resize(n, {-1, -1});
        for(int i = 0; i < n; i++) arr[i] = {robots[i], distance[i]};
        sort(arr.begin(), arr.end()); sort(walls.begin(), walls.end());
        return rec(0, 0, -1, walls);
    }
};