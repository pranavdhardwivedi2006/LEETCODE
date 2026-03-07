class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans; int n = s.size();
        vector<int> trk(26, -1);
        for(int i = 0; i < n; i++) {
            if(trk[s[i]-'a'] == -1 || trk[s[i]-'a'] + k <= ans.size()) {
                ans += s[i];
                trk[s[i]-'a'] = ans.size();
            } 
        }
        return ans;
    }
};