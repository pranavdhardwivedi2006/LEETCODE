class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(auto it : nums) mpp[it]++;
        int  ans = 0;
        for(auto [u, v] : mpp) if(v % k == 0) ans += u * v;
        return ans;
    }
};