#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto it : nums) ans += (maxi - it);
        return ans;
    }
};