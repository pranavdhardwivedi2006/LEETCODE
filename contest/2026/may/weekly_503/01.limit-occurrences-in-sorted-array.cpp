class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int, int> mpp;
        vector<int> ans;
        for(auto it : nums) {
            if(mpp[it] < k) {
                ans.push_back(it);
            }
            mpp[it]++;
        }
        return ans;
    }
};