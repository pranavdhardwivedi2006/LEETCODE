class Solution {
bool find(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<long long> pre(n); long long sum = 0;
    int pref[100001] = {0}, post[100001] = {0};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += grid[i][j];
            post[grid[i][j]]++;
        }
        pre[i] = sum;
    }
    for(int i = 0; i < n; i++) {
        if(pre[i] * 2 == sum) return true;
        for(int j = 0; j < m; j++) {
            if(i < n - 1 || j == 0 || j == m -1) post[grid[i][j]]--;
            if(i || j == 0 || j == m - 1) pref[grid[i][j]]++;
        }
        if(i == 1) for(int j = 1; j < m - 1; j++) pref[grid[0][j]]++;
        if(i == n - 2) for(int j = 1; j < m - 1; j++) post[grid[n-1][j]]--;
        long long x = abs(2 * pre[i] - sum);
        if(2 * pre[i] > sum && x >= 0 && x < 100001 && pref[x]) return true;
        if(2 * pre[i] < sum && x >= 0 && x < 100001 && post[x]) return true;
    }
    return false;
}
bool find2(vector<vector<int>>& grid) {
    int n = max(grid.size(), grid[0].size());
    vector<int> arr(n); int i = 0;
    for(auto& it : grid) for(auto& x : it) arr[i++] = x;
    long long sum = 0, curr = 0;
    for(auto& it : arr) sum += it;
    for(auto& it : arr) {
        if(curr * 2 == sum) return true;
        if(curr * 2 == sum - it) return true;
        curr += it;
        if((curr - arr[0]) * 2 == sum - arr[0]) return true;
        if(curr * 2 == sum - arr[n-1]) return true;
    }
    return false;
}
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n == 1 || m == 1) return find2(grid);
        vector<vector<int>> transpose(m, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) transpose[j][i] = grid[i][j];
        }
        return find(grid) | find(transpose);
    }
};