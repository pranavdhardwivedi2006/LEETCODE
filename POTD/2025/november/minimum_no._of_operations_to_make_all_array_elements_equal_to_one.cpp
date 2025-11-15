#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(); int x = INT_MAX, cnt = 0;
        for(int i = 0; i < n; i++) {
            int gcd = nums[i];
            if(nums[i] == 1) cnt++;
            for(int j = i; j < n; j++) {
                gcd = std::gcd(nums[j], gcd);
                if(gcd == 1) {x = min(x, j - i + 1); break;}
            }
        }
        return cnt ? n - cnt : x == INT_MAX ? -1 : n + x - 2;
    }
};