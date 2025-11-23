class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n) {
            s += (n & 1) + '0';
            n >>= 1;
        } int ans = 0;
        string t = s; reverse(t.begin(), t.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i]) ans++;
        }
        return ans;
    }
};