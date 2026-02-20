class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k = !(n & 1);
        while(n) {
            if((n & 1 ^ k) == 0) return false;
            n >>= 1; k = !k;
        }
        return true;
    }
};