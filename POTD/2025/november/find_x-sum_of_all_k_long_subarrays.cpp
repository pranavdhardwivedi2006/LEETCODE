class Solution {
private:
    int find(map<int, int, greater<int>>& mpp, int k) {
        map<int, vector<int>, greater<int>> mp;
        int ans = 0;
        for(auto [u, v] : mpp) mp[v].push_back(u);
        for(auto& [u, v] : mp) {
            for(auto& x : v) {
                ans += u * x; 
                k--; if(!k) return ans;
            }
        }
        return ans;
    } 
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int, int, greater<int>> mpp; vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            if(i < k - 1) continue;
            ans.push_back(find(mpp, x));
            if(--mpp[nums[i-k+1]] == 0) mpp.erase(nums[i-k+1]);
        }
        return ans;
    }
};