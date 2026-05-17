class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int cnt = 0, n = matrix.size(), m = matrix[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
        vector<tuple<int, int, int>> vis;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) pq.push({matrix[i][j], i, j});
            }
        }
        while(!pq.empty()) {
            auto [val, x, y] = pq.top(); pq.pop();
            bool found = true;
            for(auto& [val1, x1, y1] : vis) {
                if(val1 == val) break;
                if(abs(x1 - x) == val && abs(y1 - y) == val) continue;
                if(x - val <= x1 && x + val >= x1 && y - val <= y1 && y + val >= y1) {
                    found = false;
                    break;
                }
            }
            if(found) cnt++;
            vis.push_back({val, x, y});
        }
        return cnt;
    }
};