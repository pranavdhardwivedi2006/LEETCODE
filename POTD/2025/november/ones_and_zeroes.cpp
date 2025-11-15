#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<pair<int, int>> arr;
vector<vector<vector<int>>> dp;
private:
    int find(int index, int n, int m) {
        if(index >= arr.size()) return 0;
        if(dp[index][n][m] != -1) return dp[index][n][m];
        int leave = find(index + 1, n, m);
        int take = 0; auto [u, v] = arr[index];
        if(n >= u && m >= v) take = 1 + find(index + 1, n - u, m - v);
        return dp[index][n][m] = max(take, leave);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(auto& it : strs) {
            int zero = 0, one = 0;
            for(auto& x : it) {
                if(x == '0') zero++;
                else one++;
            }
            arr.push_back({one, zero});
        }
        dp.resize(arr.size(), vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
        return find(0, n, m);
    }
};