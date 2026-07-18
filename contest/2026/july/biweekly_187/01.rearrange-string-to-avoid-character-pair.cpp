class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if(x > y) sort(s.begin(), s.end());
        else sort(s.rbegin(), s.rend());
        return s;
    }
};