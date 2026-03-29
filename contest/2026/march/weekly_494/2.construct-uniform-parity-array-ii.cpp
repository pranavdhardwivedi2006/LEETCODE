class Solution {
bool even(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++) if(nums[i] & 1) return false;
    return true;
}
bool odd(vector<int>& nums) {
    int maxi = *min_element(nums.begin(), nums.end());
    return maxi & 1;
}
public:
    bool uniformArray(vector<int>& nums1) {
        return even(nums1) | odd(nums1);
    }
};