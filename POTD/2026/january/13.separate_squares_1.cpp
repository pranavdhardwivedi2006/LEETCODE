class Solution {
private:
    void find(vector<vector<int>>& squares, double mid, double& upr, double& lwr, int n) {
        for (int i = 0; i < n; i++) {
            double y = squares[i][1];
            double l = squares[i][2];
            double top = y + l;
            if (top <= mid) lwr += l * l;
            else if (mid <= y) upr += l * l;
            else {
                lwr += l * (mid - y);
                upr += l * (top - mid);
            }
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 0;
        int n = squares.size();
        for (int i = 0; i < n; i++) {
            low = min(low, (double)squares[i][1]);
            high = max(high, (double)(squares[i][1] + squares[i][2]));
        }
        while (high - low > 1e-5) {
            double mid = low + (high - low) / 2.0;
            double upr = 0, lwr = 0;
            find(squares, mid, upr, lwr, n);
            if (lwr >= upr) high = mid;
            else low = mid;
        }
        return low;
    }
};