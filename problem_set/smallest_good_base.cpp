class Solution {
private:
    long long calc(int n, long long mid) {
        long long ans = 1, trk = 1;
        for(int i = 1; i < n; i++) {
            if(mid >= LLONG_MAX / trk) return LLONG_MAX;
            trk *= mid;
            if(ans >= LLONG_MAX - trk) return LLONG_MAX;
            ans += trk;
        }
        return ans;
    }
    long long find(int n, long long x) {
        long long l = 2, r = x - 1;
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            long long k = calc(n, mid);
            if(k == x) return mid;
            if(k < x) l = mid + 1;
            else r = mid - 1;
        }
        return x;
    }
public:
    string smallestGoodBase(string n) {
        long long x = stoll(n);
        long long ans = x - 1;
        for(int i = 3; i < 64; i++) {
            ans = min(ans, find(i, x));
        }
        return to_string(ans);
    }
};