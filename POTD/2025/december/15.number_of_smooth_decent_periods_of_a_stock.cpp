#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int l = 0, r = 1, n = prices.size();
        if(n == 1) return 1;
        long long ans = 0;
        while(r < n) {
            if(l == r) r++;
            while(r < n && prices[r] - prices[r-1] == -1) r++;
            ans += 1LL * (r - l + 1) * (r - l) / 2;
            l = r;
        }
        return ans;
    }
};