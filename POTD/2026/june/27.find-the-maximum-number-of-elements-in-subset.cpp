class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(auto& it : nums) mpp[it]++;
        int ans = (mpp[1] & 1) ? mpp[1] : mpp[1] - 1;
        for(auto& it : nums) {
            long long k = it;
            int cnt = -1;
            while(k <= 1e9 && k != 1) {
                if(mpp.find(k) == mpp.end()) break;
                cnt += 2; ans = max(ans, cnt);
                if(mpp[k] == 1) break;
                k *= k;
            }
        }
        return ans;
    }
};