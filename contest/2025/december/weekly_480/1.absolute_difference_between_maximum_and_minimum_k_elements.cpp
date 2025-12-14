#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum2 = 0, sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        for(int i = n - 1; i >= n - k; i--) sum2 += nums[i];
        return sum2 - sum;
    }
};