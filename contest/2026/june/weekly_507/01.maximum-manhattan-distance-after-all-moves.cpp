class Solution {
public:
    int maxDistance(string moves) {
        int k = 0, x = 0, y = 0;
        for(auto it : moves) {
            if(it == 'L') x--;
            if(it == 'R') x++;
            if(it == 'U') y++;
            if(it == 'D') y--;
            if(it == '_') k++;
        }
        return abs(x) + abs(y) + k;
    }
};