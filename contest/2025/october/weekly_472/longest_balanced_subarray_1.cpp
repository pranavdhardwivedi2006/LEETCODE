class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            set<int> st, st1;
            for(int j = i; j < n; j++) {
                if(nums[j] & 1) st.insert(nums[j]);
                else st1.insert(nums[j]);
                if(st.size() == st1.size()) ans = max(ans, j - i + 1);
            }
        }
        return ans;       
    }
};