class Solution {
public:
    int minFlips(string s) {
        int zero = 0, one = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') one++;
            else zero++;
        }
        if(s[0] == '1') one--;
        if(s[n-1] == '1') one--;
        if(s[0] != '1' && s[n-1] != '1') one--;
        one = max(one, 0);
        return min(one, zero);
    }
};