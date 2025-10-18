class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long prev = -1e10; int ans = 0;
        for(auto& it : nums) {
            if(prev < it - k) ans++, prev = it - k;
            else if(prev < it + k) ans++, prev++;
        }
        return ans;
    }
};