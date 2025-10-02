class Solution {
private:
    double find(double x1, double y1, double z1, double x2, double y2, double z2) {
        return 0.5 * abs((x2 - y2) * z1 + (y2 - z2) * x1 + (z2 - x2) * y1);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size(); double maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    double x1 = points[i][0], y1 = points[j][0], z1 = points[k][0];
                    double x2 = points[i][1], y2 = points[j][1], z2 = points[k][1];
                    maxi = max(maxi, find(x1, y1, z1, x2, y2, z2));
                }
            }
        }
        return maxi;
    }
};