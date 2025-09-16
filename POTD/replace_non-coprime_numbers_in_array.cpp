#include <bits/stdc++.h> 
using namespace std;// For std::gcd and std::lcm

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i], k = nums[i];
            while(!ans.empty() && k != 1) {
                k = gcd(ans.back(), num);
                if(k != 1) {
                    num = lcm(num, ans.back());
                    ans.pop_back();
                }
            } 
            ans.push_back(num);
        }
        return ans;
    }
};