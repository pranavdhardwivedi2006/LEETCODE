#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int mini = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] != nums[j]) continue;
                for(int k = j + 1; k < n; k++) {
                    if(nums[k] == nums[j]) {
                        int p = j - i + k - j + k - i;
                        mini = min(mini, p);
                    }
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};