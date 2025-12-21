#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> mpp(26, 0);
        int n = s.size(), x = s.size();
        for(int i = 0; i < n; i++) {
            mpp[s[i]-'a'] += cost[i];
        }
        sort(mpp.begin(), mpp.end(), greater<long long>());
        long long ans = 0;
        for(int i = 1; i < 26; i++) ans += mpp[i];
        return ans;
    }
};