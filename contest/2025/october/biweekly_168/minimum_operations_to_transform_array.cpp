class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        for(auto it : nums1) st.insert(it); bool found = false;
        long long ans = 1; int num = INT_MAX, k = nums2[n];
        for(int i = 0; i < n; i++) {
            if(k <= nums1[i] && k >= nums2[i]) found = true;
            if(k <= nums2[i] && k >= nums1[i]) found = true;
            num = min({num, abs(k - nums1[i]), abs(k - nums2[i])});
            ans += abs(nums1[i] - nums2[i]);
        }
        if(!found) ans += num;
        return ans;
    }
};