class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long op = 0, MOD = 1e9 + 7;
        int idx = 0, n = nums.size();
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(nums[i] < a) {
                op = (op + i - idx) % MOD;
                idx++;
            } else {
                temp.push_back(nums[i]);
            }
        }
        idx = 0;
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] > b) {
                op = (op + i - idx) % MOD;
                idx++;
            }
        }
        return op;
    }
};