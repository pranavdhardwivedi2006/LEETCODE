class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int ans = 0, i = 0;
        while(n) {
            ans = (ans << 1) | !(n & 1);
            n >>= 1;
        }
        return ans;
    }
};