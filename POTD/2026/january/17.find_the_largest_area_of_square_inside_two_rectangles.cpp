class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0, side;
        for(int i = 0; i < n; i++) {
            int bottom = bottomLeft[i][0], left = bottomLeft[i][1];
            int up = topRight[i][0], right = topRight[i][1];
            for(int j = i + 1; j < n; j++) {
                int b = bottomLeft[j][0], l = bottomLeft[j][1];
                int u = topRight[j][0], r = topRight[j][1];
                if(b > up || u < bottom || l > right || r < left) continue ;
                side = min(min(r, right) - max(l, left), min(u, up) - max(b, bottom));
                ans = max(ans, side * side);
            }
        }
        return ans;
    }
};