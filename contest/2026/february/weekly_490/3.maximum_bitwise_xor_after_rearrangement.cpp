class Solution {
public:
    string maximumXor(string s, string t) {
        int one = 0, zero = 0, n = s.size();
        for(auto& it : t) it == '0' ? zero++ : one++;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                if(one) t[i] = '1', one--;
                else t[i] = '0', zero--;
            }
            else {
                if(zero) t[i] = '0', zero--;
                else t[i] = '1', one--;
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) t[i] = '0';
            else t[i] = '1';
        }
        return t;
    }
};