class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mpp1, mpp2;
        for(auto it : nums) mpp1[it]++;
        for(auto [u, v] : mpp1) mpp2[v]++;
        for(auto it : nums) {
            if(mpp2[mpp1[it]] == 1) return it;
        }
        return -1;
    }
};