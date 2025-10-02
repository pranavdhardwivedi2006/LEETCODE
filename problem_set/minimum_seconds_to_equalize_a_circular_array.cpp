class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp; int n = nums.size();
        for(int i = 0; i < n; i++) mpp[nums[i]].push_back(i);
        int ans = INT_MAX;
        for(auto& it : mpp) {
            int cnt = 0, m = it.second.size();
            cnt = max(cnt, (it.second[0] + n - it.second[m-1]) / 2);
            for(int i = 1; i < m; i++) cnt = max(cnt, (it.second[i] - it.second[i-1]) / 2);
            ans = min(ans, cnt);
        }
        return ans;
    }
};