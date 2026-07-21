class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> blocks;
        int i = 0, n = s.size(), one = 0;
        while(i < n && s[i] == '1') i++, one++;
        while(i < n) {
            int cnt = 0;
            while(i < n && s[i] == '0') i++, cnt++;
            blocks.push_back(cnt);
            while(i < n && s[i] == '1') i++, one++;
        }
        int ans = 0;
        for(int i = 1; i < blocks.size(); i++) {
            ans = max(ans, blocks[i] + blocks[i-1]);
        }
        return ans + one;
    }
};