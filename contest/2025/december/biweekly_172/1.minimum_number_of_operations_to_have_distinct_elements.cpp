#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        set<int> st;
        while(r < n) {
            if(st.find(nums[r]) != st.end()) {
                while(l < n && nums[l] != nums[r]) st.erase(nums[l++]); 
                st.erase(nums[l++]);
            }
            st.insert(nums[r++]);
        }
        int ans = l / 3;
        if(l % 3) ans++;
        return ans;
    }
};