class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1) {
            vector<int> trk;
            for(int i = 1; i < nums.size(); i++) trk.push_back((nums[i] + nums[i-1]) % 10);
            nums = trk;
        }
        return nums[0];
    }
};