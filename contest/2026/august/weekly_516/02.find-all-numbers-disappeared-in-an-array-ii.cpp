class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) {
            vector<int> temp = {0, -1};
            if(lower < nums[i]) {
                temp[0] = lower;
                if(nums[i] > upper) {
                    temp[1] = upper;
                } else {
                    temp[1] = nums[i] - 1;
                }
            }
            lower = max(lower, nums[i] + 1);
            if(temp[0] <= temp[1]) ans.push_back(temp); 
        }
        if(lower <= upper) ans.push_back({lower, upper});
        return ans;
    }
};