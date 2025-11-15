#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mpp; int n = nums.size(), mini = INT_MAX;
        for(int i = 0; i < n; i++) mpp[nums[i]].push_back(i);
        for(auto& it : mpp) {
            if(it.second.size() < 3) continue;
            for(int i = 2; i < it.second.size(); i++) {
                int p = 2 * it.second[i] - 2 * it.second[i-2];
                mini = min(p, mini);
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
