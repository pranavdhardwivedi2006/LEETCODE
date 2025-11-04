#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 0, i;
        vector<int> n;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i - j) {
                n.push_back(nums[i]);
                j++;
            }
            if (j == 2) break;
        }
        return n;
    }
};