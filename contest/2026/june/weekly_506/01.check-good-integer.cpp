class Solution {
public:
    bool checkGoodInteger(int n) {
        int dsum = 0, sqsum = 0;
        while(n) {
            int d = n % 10;
            dsum += d;
            sqsum += d * d;
            n /= 10;
        }
        return sqsum - dsum >= 50;
    }
};