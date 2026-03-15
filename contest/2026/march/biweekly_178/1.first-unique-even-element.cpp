class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) continue;
            bool find = false;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == nums[i]) {
                    find = true;
                    nums[j] = 1;
                }
            }
            if(!find) return nums[i];
        }
        return -1;
    }
};