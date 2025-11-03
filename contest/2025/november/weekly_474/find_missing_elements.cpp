#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums[0], n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            while(x < nums[i]) ans.push_back(x++);
            if(x == nums[i]) x++;
        }
        return ans;
    }
};