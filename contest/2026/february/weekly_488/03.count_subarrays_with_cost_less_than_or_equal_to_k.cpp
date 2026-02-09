class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0; set<pair<int, int>> st;
        int n = nums.size(), l = 0, r = 0;
        while(r < n) {
            st.insert({nums[r], r});
            long long x = st.begin() -> first;
            long long y = (--st.end()) -> first;
            while((y - x) * (r - l + 1) > k) {
                st.erase({nums[l], l}); l++;
                x = st.begin() -> first;
                y = (--st.end()) -> first;
            }
            ans += r++ - l + 1;
        }      
        return ans;
    }
};