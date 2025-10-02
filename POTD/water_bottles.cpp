class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int f = numBottles, e = numExchange, sum = 0, sum1 = 0;
        while (f != 0) {
            sum += f;
            f += sum1;
            sum1 = f % e;
            f = f / e;
        }
        return sum;
    }
};