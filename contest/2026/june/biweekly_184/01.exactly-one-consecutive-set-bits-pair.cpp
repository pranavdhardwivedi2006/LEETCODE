class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0, x = 0;
        while(n) {
            if(n & 1) cnt++;
            else cnt = 0;
            if(cnt >= 2) x++;
            n >>= 1;
        }
        return x == 1;
    }
};