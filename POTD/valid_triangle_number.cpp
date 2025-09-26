class Solution {
private:
    int binary_search(int l, int r, int k, vector<int>& nums) {
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] <= k) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(!nums[i]) continue;
            for(int j = i + 1; j < n - 1; j++) {
                int k = nums[i] + nums[j] - 1;
                ans += binary_search(j, n - 1, k, nums) - j;
            }
        }
        return ans;
    }
};