class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(k == 0) return n;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1] && n - i - 1 >= k) {
                return i + 1;
            }
        }
        return 0;
    }
};