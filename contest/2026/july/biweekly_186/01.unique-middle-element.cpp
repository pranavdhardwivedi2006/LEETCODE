class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        map<int, int> mpp;
        for(auto& it : nums) mpp[it]++;
        return mpp[nums[nums.size() / 2]] == 1;
    }
};