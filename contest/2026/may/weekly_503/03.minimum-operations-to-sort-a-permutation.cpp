class Solution {
int rotate(vector<int>& nums) {
    int k1 = 0, k2 = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) k1 = i; 
        if(nums[i] == n - 1) k2 = i; 
    }
    vector<int> ans1(n), ans2(n);
    for(int i = 0; i < n; i++) {
        ans1[(i-k1+n)%n] = nums[i];
        ans2[(i-k2+n)%n] = nums[i];
    }
    int ans = INT_MAX;
    reverse(ans2.begin(), ans2.end());
    if(is_sorted(ans1.begin(), ans1.end())) ans = k1;
    if(is_sorted(ans2.begin(), ans2.end())) ans = min(ans, k2 + 1);
    return ans;
}
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = rotate(nums);
        reverse(nums.begin(), nums.end());
        int k = rotate(nums);
        if(k != INT_MAX) k++;
        ans = min(ans, k);
        return ans == INT_MAX ? -1 : ans;
    }
};