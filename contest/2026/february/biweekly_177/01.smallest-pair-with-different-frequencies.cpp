class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> mpp;
        for(auto& it : nums) mpp[it]++;
        for(auto& [u, v] : mpp) {
            for(auto& [x, y] : mpp) {
                if(u < x && v != y) return {u, x};
            }
        }
        return {-1, -1};
    }
};