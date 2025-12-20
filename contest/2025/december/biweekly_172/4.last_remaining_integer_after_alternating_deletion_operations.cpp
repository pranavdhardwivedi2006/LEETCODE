class Solution {
public:
    long long lastInteger(long long n) {
        if(n == 2 || n == 1) return 1;
        long long left = 1, right = (n & 1) ? n : n - 1;
        long long remain = (n + 1) / 2, diff = 2;
        bool turn = true;
        while(remain > 2) {
            if(turn) {
                if(remain % 2 == 0) left += diff;
            }
            else {
                if(remain % 2 == 0) right -= diff;
            }
            remain = (remain + 1) / 2;
            diff *= 2;
            turn = !turn;
        }
        return turn ? right : left;
    }
};