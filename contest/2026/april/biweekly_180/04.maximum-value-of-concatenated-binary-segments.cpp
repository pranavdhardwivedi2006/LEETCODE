class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<array<int, 2>> trk(n);
        for(int i = 0; i < n; i++) {
            trk[i] = {nums1[i], nums0[i]};
        }
        sort(trk.begin(), trk.end(), [](array<int, 2>& a, array<int, 2>& b) {
            if(a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        long long num = 0, MOD = 1e9 + 7;
        for(auto& it : trk) {
            if(it[1]) continue;
            for(int i = 0; i < it[0]; i++) {
                num <<= 1; num++; num %= MOD;
            }
        }
        for(auto& it : trk) {
            if(!it[1]) continue;
            for(int i = 0; i < it[0]; i++) {
                num <<= 1; num++; num %= MOD;
            }
            for(int i = 0; i < it[1]; i++) {
                num <<= 1; num %= MOD;
            }
        }
        return num;
    }
};