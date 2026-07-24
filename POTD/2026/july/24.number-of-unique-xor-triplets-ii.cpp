class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> ans, vis;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int xr = nums[i] ^ nums[j];
                if(vis.count(xr)) continue;
                vis.insert(xr);
                for(int k = 0; k < n; k++) {
                    ans.insert(xr ^ nums[k]);
                }
            }
        }
        return ans.size();
    }
};