class Solution {
public:
    int mirrorFrequency(string s) {
        int ans = 0;
        unordered_map<char, int> mpp;
        for(auto& it : s) mpp[it]++;
        for(int i = 0; i < 13; i++) {
            ans += abs(mpp['a'+i] - mpp['z'-i]);
        }
        for(int i = 0; i < 5; i++) {
            ans += abs(mpp['0'+i] - mpp['9'-i]);
        }
        return ans;
    }
};