class Solution {
char rec(int k, int comb) {
    if(k == 1) return '0';
    int x = comb / 2 + 1;
    if(k == x) return '1';
    if(k < x) return rec(k, x - 1);
    return rec(2 * x - k, x - 1) == '0' ? '1' : '0';
}
public:
    char findKthBit(int n, int k) {
        int comb = (1 << n) - 1;
        return rec(k, comb);
    }
};
