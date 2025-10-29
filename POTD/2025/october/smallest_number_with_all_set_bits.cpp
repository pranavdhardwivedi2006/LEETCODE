class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 0;
        while(n) {
            n >>= 1;
            cnt++;
        }
        return (1 << cnt) - 1;
    }
};