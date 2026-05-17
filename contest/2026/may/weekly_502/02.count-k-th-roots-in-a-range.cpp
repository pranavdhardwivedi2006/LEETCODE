class Solution {
long long power(long long x, long long y) {
    long long mult = 1;
    while(y--) {
        mult *= x;
        if(mult > 1e9) break;
    }
    return mult;
}
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        int l1 = 0, r1 = 1e6;
        while(l1 <= r1) {
            int mid = (l1 + r1) / 2;
            long long p = power(mid, k);
            if(p >= l) r1 = mid - 1;
            else l1 = mid + 1;
        }
        int l2 = 0, r2 = 1e6;
        while(l2 <= r2) {
            int mid = (l2 + r2) / 2;
            long long p = power(mid, k);
            if(p <= r) l2 = mid + 1;
            else r2 = mid - 1;
        }
        return max(0, r2 - l1 + 1);
    }
};