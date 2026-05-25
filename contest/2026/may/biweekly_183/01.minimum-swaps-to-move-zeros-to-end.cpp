class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int cnt = 0, n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) cnt++;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(n - i > cnt && !nums[i]) ans++;
        }
        return ans;
    }
};