class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0; for(auto it : nums) ans += min(1, it % 3);
        return ans;
    }
};