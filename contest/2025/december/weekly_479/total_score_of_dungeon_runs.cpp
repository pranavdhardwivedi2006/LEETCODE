class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        long long ans = 0, n = damage.size(), prev = 0; 
        vector<long long> trk(n);
        for(int i = n - 1; i >= 0; i--) {
            trk[i] = prev += damage[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            int l = 0, r = i;
            long long prev = i == n - 1 ? 0 : trk[i+1];
            long long req = requirement[i] - prev;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(trk[mid] + req <= hp) r = mid - 1;
                else l = mid + 1;
            }
            ans += l;
        } 
        return 1LL * n * (n + 1) / 2 - ans;
    }
};