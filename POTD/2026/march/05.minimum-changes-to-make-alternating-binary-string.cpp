class Solution {
public:
    int minOperations(string s) {
        int oz = 0, ez = 0, oo = 0, eo = 0;
        for(int i = 0; i < s.size(); i++) {
            if(i & 1) s[i] == '0' ? oz++ : oo++;
            else s[i] == '0' ? ez++ : eo++;
        }
        return min(oz + eo, ez + oo);
    }
};