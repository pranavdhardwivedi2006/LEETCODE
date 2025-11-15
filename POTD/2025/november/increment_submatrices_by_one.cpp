#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for(auto& it : queries) {
            int row1 = it[0], row2 = it[2];
            int col1 = it[1], col2 = it[3];
            for(int i = row1; i <= row2; i++) {
                ans[i][col1] += 1;
                if(col2 + 1 < n) ans[i][col2+1] -= 1;
            }
        }
        for(auto& it : ans) {
            int k = 0;
            for(auto& x : it) x = k += x;
        }
        return ans;
    }
};