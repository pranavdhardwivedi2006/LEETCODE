class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> mpp;
        for(auto& it : nums1) mpp[it].first++;
        for(auto& it : nums2) mpp[it].second++;
        int ans = 0;
        for(auto& [u, v] : mpp) {
            int cnt = v.first + v.second;
            if(cnt & 1) return -1;
            ans += abs(cnt / 2 - v.first);
        }
        return ans / 2;
    }
};