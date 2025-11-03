#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i = 0, n = colors.size();
        int ans = 0;
        while(i < n - 1) {
            char c = colors[i];
            int maxi = 0, sum = 0;
            while(colors[i] == c) {
                maxi = max(maxi, neededTime[i]);
                sum += neededTime[i];
                i++;
            }
            ans += sum - maxi;
        }
        return ans;
    }
};