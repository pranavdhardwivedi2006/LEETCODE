class Solution {
public:
    int countBinarySubstrings(string s) {
        int res = 0, prev = 0, curr = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) curr++;
            else {
                prev = curr;
                curr = 1;
            }
            if (curr <= prev) res++;
        }
        return res;
    }
};
