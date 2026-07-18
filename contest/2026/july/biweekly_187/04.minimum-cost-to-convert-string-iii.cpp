class Solution {
int rec(int index, vector<int>& dp, string& source, string& target, vector<vector<string>>& rules, vector<int>& costs) {
    if(index >= source.size()) return 0;
    if(dp[index] != -1) return dp[index];
    int cost = INT_MAX, n = source.size();
    for(int i = 0; i < rules.size(); i++) {
        bool found = true;
        int cnt = 0;
        for(int j = 0; j < rules[i][1].size(); j++) {
            if(index + j >= n || rules[i][1][j] != target[index+j]) {
                found = false;
                break;
            }
            if(index + j >= n || (rules[i][0][j] != '*' && rules[i][0][j] != source[index+j])) {
                found = false;
                break;
            }
            if(rules[i][0][j] == '*') cnt++;
        }
        if(!found) continue;
        int temp = rec(index + rules[i][1].size(), dp, source, target, rules, costs);
        if(temp == INT_MAX) continue;
        cost = min(cost, temp + cnt + costs[i]);
    }
    int temp = INT_MAX;
    if(source[index] == target[index]) temp = rec(index + 1, dp, source, target, rules, costs);
    return dp[index] = min(temp, cost);
}
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        if(source == target) return 0;
        int n = source.size();
        vector<int> dp(n, -1);
        int ans = rec(0, dp, source, target, rules, costs);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};