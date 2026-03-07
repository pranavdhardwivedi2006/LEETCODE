class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0, i = 0, n = s.size();
        while(i < n) {
            char c = s[i];
            if(c == '1') cnt++;
            while(i < n && c == s[i]) i++;
        }
        return cnt < 2;
    }
};