class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = -1; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                if(j != i) temp.push_back(nums[j]);
            }
            vector<int> suff(temp.size()), pref(temp.size());
            int prev = 0;
            for(int j = temp.size() - 1; j >= 0; j--) {
                suff[j] = prev = gcd(prev, temp[j]);
            }
            prev = 0;
            for(int j = 0; j < temp.size(); j++) {
                pref[j] = prev = gcd(prev, temp[j]);
            }
            int cnt = 0;
            for(int i = 1; i < pref.size(); i++) {
                if(pref[i-1] == suff[i]) cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};