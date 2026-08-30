class Solution {
bool checkDiagonal(int x, int y, int m, int n) {
    int x1 = x, y1 = y;
    while(x1 > 0 && y1 > 0) {
        if(x1 == m && y1 == n) return true;
        x1--; y1--;
    }
    x1 = x, y1 = y;
    while(x1 <= 8 && y1 <= 8) {
        if(x1 == m && y1 == n) return true;
        x1++; y1++;
    }
    x1 = x, y1 = y;
    while(x1 > 0 && y1 <= 8) {
        if(x1 == m && y1 == n) return true;
        x1--; y1++;
    }
    x1 = x, y1 = y;
    while(x1 <= 8 && y1 > 0) {
        if(x1 == m && y1 == n) return true;
        x1++; y1--;
    }
    return false;
}
public:
    int minBishopMoves(vector<int>& sc, vector<int>& tr) {
        int s = (sc[0] + sc[1]) & 1;
        int t = (tr[0] + tr[1]) & 1;
        if(s != t) return -1;
        if(sc[0] == tr[0] && sc[1] == tr[1]) return 0;
        if(checkDiagonal(sc[0], sc[1], tr[0], tr[1])) return 1;
        return 2;
    }
};