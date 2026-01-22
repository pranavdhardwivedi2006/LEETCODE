class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            int min = INT_MAX;
            int x;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < min) {
                    min = sum;
                    x = i;
                }
            }
            nums[x] = min;
            nums.erase(nums.begin() + x + 1);
            cnt++;
        }
        return cnt;
    }
};