class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>> bit(32);
        for(auto it : nums) {
            int i = 31;
            int k = it;
            while(it) {
                if(it & 1) bit[i].push_back(k);
                i--; it >>= 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            if(bit[i].empty()) continue;
            vector<int> trk;
            trk.push_back(bit[i][0]);
            for(int j = 1; j < bit[i].size(); j++) {
                if(bit[i][j] > trk.back()) trk.push_back(bit[i][j]);
                else {
                    int low = lower_bound(trk.begin(), trk.end(), bit[i][j]) - trk.begin();
                    trk[low] = bit[i][j];
                }
            }
            int n = trk.size();
            ans = max(ans, n);
        }
        return ans;
    }
};