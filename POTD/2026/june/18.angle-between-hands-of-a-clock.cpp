class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = hour % 12 * 30.0;
        ans += minutes / 2.0;
        ans = abs(ans - minutes * 6.0);
        return min(ans, 360.0 - ans);
    }
};