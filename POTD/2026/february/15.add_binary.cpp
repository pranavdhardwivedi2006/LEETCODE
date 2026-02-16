class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) return addBinary(b, a);
        string s(b.size() - a.size(), '0');
        a = s + a;
        int i = a.size() - 1, c = 0;
        string ans;
        while (i >= 0) {
            if (a[i] == '0' && b[i] == '0') {
                if (c == 1) {
                    ans = '1' + ans;
                    c = 0;
                } else
                    ans = '0' + ans;
            } else if (a[i] == '1' && b[i] == '1') {
                if (c == 1) {
                    ans = '1' + ans;
                } else {
                    ans = '0' + ans;
                    c = 1;
                }
            } else {
                if (c == 1) {
                    ans = '0' + ans;
                    c = 1;
                } else {
                    ans = '1' + ans;
                }
            }
            i--;
        }
        if (c == 1)
            ans = '1' + ans;
        return ans;
    }
};