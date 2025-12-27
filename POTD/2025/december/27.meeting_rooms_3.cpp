class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> end;
        for(int i = 0; i < n; i++) free.push(i);
        vector<int> ans(n, 0);
        for(auto it : meetings) {
            int u = it[0], v = it[1];
            while(!end.empty() && end.top().first <= u) {
                free.push(end.top().second);
                end.pop();
            }
            if(free.empty()) {
                auto [x, y] = end.top();
                end.pop();
                end.push({x + v - u, y});
                ans[y]++; 
            }
            else {
                int k = free.top();
                free.pop();
                end.push({v, k});
                ans[k]++;
            }
        }
        int idx = 0, maxi = ans[0];
        for(int i = 0; i < n; i++) {
            if(maxi < ans[i]) {
                idx = i;
                maxi = ans[i];
            }
        }
        return idx;
    }
};