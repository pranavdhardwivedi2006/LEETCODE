class Solution {
bool check(int st, string& s1, string& s2) {
    int cnt1[26] = {0}, cnt2[26] = {0};
    for(int i = st; i < s1.size(); i += 2) cnt1[s1[i]-'a']++;
    for(int i = st; i < s2.size(); i += 2) cnt2[s2[i]-'a']++;
    for(int i = 0; i < 26; i++) if(cnt1[i] != cnt2[i]) return false;
    return true;
}
public:
    bool checkStrings(string s1, string s2) {
        return check(0, s1, s2) & check(1, s1, s2);
    }
};