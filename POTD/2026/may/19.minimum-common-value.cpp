class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, n1 = nums1.size();
        int r = 0, n2 = nums2.size();
        while(l < n1 && r < n2) {
            if(nums1[l] == nums2[r]) return nums1[l];
            if(nums1[l] < nums2[r]) l++;
            else r++;
        }
        return -1;
    }
};