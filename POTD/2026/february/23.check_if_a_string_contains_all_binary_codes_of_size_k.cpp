class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int num = 0, n = s.size();
        if(k > n) return false;
        vector<bool> trk(1 << k, false);
        for(int i = 0; i < k; i++) {
            num <<= 1; num |= s[i] - '0';
        }
        trk[num] = true; int x = (1 << k) - 1;
        for(int i = k; i < n; i++) {
            num <<= 1; num |= s[i] - '0';
            num &= x; trk[num] = true;
        }
        bool ans = true;
        for(auto it : trk) ans &= it;
        return ans;
    }
};