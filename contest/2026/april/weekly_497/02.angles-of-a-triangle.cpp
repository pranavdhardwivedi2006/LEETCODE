class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        if(sides[0] + sides[1] <= sides[2]) return {};
        double a = sides[0], b = sides[1], c = sides[2];
        double x = acos((double)(b * b + a * a - c * c) / (2 * a * b)) * 180 / M_PI;
        double y = acos((double)(b * b - a * a + c * c) / (2 * b * c)) * 180 / M_PI;
        double z = acos((double)(- b * b + a * a + c * c) / (2 * a * c)) * 180 / M_PI;
        vector<double> ans = {x, y, z}; sort(ans.begin(), ans.end());
        return ans;
    }
};