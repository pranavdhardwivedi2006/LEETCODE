class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans; int rem = 0;
        for(auto& it : nums) {
            rem <<= 1;
            if(it == 1) rem += 1;
            rem %= 5;
            if(rem == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};