class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, l = 0;
        for(auto& it : moves) {
            if(it == 'U') u++;
            if(it == 'D') u--;
            if(it == 'L') l++;
            if(it == 'R') l--;
        }
        return u == 0 && l == 0;
    }
};