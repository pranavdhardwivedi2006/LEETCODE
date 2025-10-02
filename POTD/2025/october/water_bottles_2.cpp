class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int d = numBottles, n = numExchange, t = 0, e = numBottles;
        while (e >= n) {
            t++;
            e = e - n;
            n++;
            if (e < n) {
                e += t;
                d += t;
                t = 0;
            }
        }
        return d;
    }
};