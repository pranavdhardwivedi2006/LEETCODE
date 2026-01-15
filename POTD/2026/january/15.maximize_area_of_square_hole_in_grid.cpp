class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int curr = 0, maxH = 2, maxV = 2;
        int n1 = hBars.size(), m1 = vBars.size();
        for(int i = 1; i < n1; i++) {
            if(hBars[i] - hBars[i-1] == 1) curr++;
            else curr = 0;
            maxH = max(maxH, curr + 2);
        } curr = 0;
        for(int i = 1; i < m1; i++) {
            if(vBars[i] - vBars[i-1] == 1) curr++;
            else curr = 0;
            maxV = max(maxV, curr + 2);
        }
        return min(maxH, maxV) * min(maxH, maxV);
    }
};