class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(auto it : s) {
            if(it == ' ' || (it >= '0' && it <= '9')) continue ;
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') v++;
            else c++;
        }
        return c ? v / c : 0;
    }
};