#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> z, o, t;
        for(auto& it : nums) {
            if(it % 3 == 0) z.push_back(it);
            else if(it % 3 == 1) o.push_back(it);
            else t.push_back(it);
        }
        sort(z.begin(), z.end(), greater<int>());
        sort(o.begin(), o.end(), greater<int>());
        sort(t.begin(), t.end(), greater<int>());
        int nz = z.size(), no = o.size(), nt = t.size();
        int ans = 0;
        if(nz >= 3) ans = z[0] + z[1] + z[2];
        if(no >= 3) ans = max(ans, o[0] + o[1] + o[2]);
        if(nt >= 3) ans = max(ans, t[0] + t[1] + t[2]);
        if(nz >= 1 && no >= 1 && nt >= 1) ans = max(ans, z[0] + o[0] + t[0]);
        return ans;
    }
};