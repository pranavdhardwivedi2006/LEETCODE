#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), del = 0;
        vector<bool> sorted(n - 1);
        for(int j = 0; j < m; j++) {
            bool is = false;
            for(int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    is = true;
                    break;
                }
            }
            if(is) del++;
            else {
                for(int i = 0; i < n - 1; i++) {
                    if(strs[i][j] < strs[i + 1][j]) {
                        sorted[i] = true;
                    }
                }
            }
        }
        return del;
    }
};