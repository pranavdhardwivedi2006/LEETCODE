class Solution {
public:
    int reverseBits(int n) {
        int x = 0;
        for(int i = 0; i < 31; i++) {
            x |= n & (1 << i) ? 1 << (31 - i) : 0;
        }
        return x;
    }
};