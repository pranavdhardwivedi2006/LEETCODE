#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(auto& it : nums) it = abs(it);
        sort(nums.begin(), nums.end(), greater<int>());
        return 1LL * nums[0] * nums[1] * 1e5;
    }
};