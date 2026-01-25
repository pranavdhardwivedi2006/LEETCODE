class Solution {
private:
    long long calc(int n, int r) {
        long long ans = 1; int j = 1;
        if(r > n - r) r = n - r;
        for(int i = n; i > n - r; i--) {
            ans *= i;
            if(j <= r) ans /= j++;
        }
        return ans;
    }
    int find(long long& n, int k) {
        int l = 0, r = 50;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(mid < k) {l = mid + 1; continue ;}
            long long x = calc(mid, k);   
            if(x == n) mid;
            if(x < n) l = mid + 1;
            else r = mid - 1;
        }
        n -= calc(r, k);
        return r;
    }
public:
    long long nthSmallest(long long n, int k) {
        vector<int> trk(64);
        while(k > 0) {
            int pos = find(n, k--);
            trk[pos] = 1;
        }
        reverse(trk.begin(), trk.end());
        long long ans = 0;
        for(int i = 0; i < 64; i++) {
            ans <<= 1; ans += trk[i];
        }
        return ans;
    }
};