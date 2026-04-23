class Solution {
private:
    void fill(vector<int>& idx, vector<long long>& ans) {
        vector<long long> prefix(idx.begin(), idx.end());
        int n = idx.size();
        for(int i = 1; i < n; i++) {
            prefix[i] += prefix[i-1];
        }
        long long total = prefix[n-1];
        for(int i = 0; i < n; i++) {
            long long left = 1LL * i * idx[i] - (i ? prefix[i-1] : 0);
            long long right = total - prefix[i] - 1LL * idx[i] * (n - i - 1);
            ans[idx[i]] = left + right;
        }
    }
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size(); vector<long long> ans(n);
        for(int i = 0; i < n; i++) mpp[nums[i]].push_back(i);
        for(auto& it : mpp) fill(it.second, ans);
        return ans;
    }
};