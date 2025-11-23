class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<int, int>, int> mpp; mpp[{0,0}] = -1;
        int n = nums.size(), ans = 0;
        int odd = 0, even = 0, xr = 0; 
        for(int i = 0; i < n; i++) {
            (nums[i] & 1) ? odd++ : even++;
            int k = odd - even; xr ^= nums[i];
            auto it = make_pair(k, xr); 
            if(mpp.find(it) != mpp.end()) {
                ans = max(ans, i - mpp[it]);
            }
            else mpp[it] = i;
        }
        return ans;
    }
};