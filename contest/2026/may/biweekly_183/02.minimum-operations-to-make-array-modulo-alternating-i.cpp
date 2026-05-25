class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(i == j) continue;
                int op = 0;
                for(int l = 0; l < n; l++) {
                    int x = (l & 1) ? i : j;
                    int y = nums[l] % k;
                    op += min(abs(x - y), k - abs(x - y));
                }
                ans = min(ans, op);
            }
        }
        return ans;
    }
};