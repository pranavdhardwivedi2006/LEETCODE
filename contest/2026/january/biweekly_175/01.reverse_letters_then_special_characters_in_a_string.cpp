class Solution {
public:
    string reverseByType(string s) {
        string sp, ch;
        for(auto it : s) {
            if(it >= 'a' && it <= 'z') ch += it;
            else sp += it;
        }
        reverse(sp.begin(), sp.end());
        reverse(ch.begin(), ch.end());
        int i = 0, j = 0;
        string ans;
        for(auto it : s) {
            if(it >= 'a' && it <= 'z') ans += ch[i++];
            else ans += sp[j++];
        }
        return ans;
    }
};