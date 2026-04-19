class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0, ans = 0;
        int n = nums1.size(), m = nums2.size();
        while(l < n && r < m) {
            while(r < m && nums1[l] <= nums2[r]) r++;
            ans = max(ans, r - l - 1); l++;
        }
        return ans;
    }
};