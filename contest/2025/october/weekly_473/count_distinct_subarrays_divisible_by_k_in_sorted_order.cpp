class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        map<int, int> mpp, mp; mpp[0] = 1;
        long long sum = 0, ans = 0;
        for(auto& it : nums) {
            sum += it;
            int x = sum % k;
            ans += mpp[x];
            mpp[x]++, mp[it]++;
        }
        for(auto& [u, v] : mp) {
            long long sum = 0;
            for(int i = 1; i <= v; i++) {
                sum += u;
                if(sum % k == 0) ans -= v - i;
            }
        }
        return ans;
    }
};