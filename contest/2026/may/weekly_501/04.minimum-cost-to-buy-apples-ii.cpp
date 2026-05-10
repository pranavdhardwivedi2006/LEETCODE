class Solution {
vector<vector<array<long long, 3>>> adj;
void dijkastra(int source, int index, vector<vector<long long>>& arr) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, source});
    while(!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if(arr[source][node] != -1 && arr[source][node] <= cost) continue ;
        arr[source][node] = cost;
        for(auto& it : adj[node]) {
            if(arr[source][it[0]] == -1 || arr[source][it[0]] > cost + it[index]) {
                pq.push({it[index] + cost, it[0]});
            }
        }
    }
}
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        adj.resize(n);
        vector<vector<long long>> tax(n, vector<long long>(n, -1));
        vector<vector<long long>> cost(n, vector<long long>(n, -1));
        for(auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2], 1LL * it[2] * it[3]});
            adj[it[1]].push_back({it[0], it[2], 1LL * it[2] * it[3]});
        }
        for(int i = 0; i < n; i++) dijkastra(i, 1, cost);
        for(int i = 0; i < n; i++) dijkastra(i, 2, tax);
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = prices[i];
            for(int j = 0; j < n; j++) {
                if(cost[i][j] != -1 && tax[j][i] != -1) {
                    ans[i] = min(1LL * ans[i], cost[i][j] + tax[j][i] + prices[j]);
                }
            }
        }
        return ans;
    }
};