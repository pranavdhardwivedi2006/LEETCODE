class Solution {
vector<int> pre;
private:
    long long rec(string& s, int l, int r, int e, int f) {
        if(l == r) return s[l] == '0' ? f : e;
        int cnt = pre[r] - (l ? pre[l-1] : 0), n = r - l + 1;
        if(n & 1) return cnt ? 1LL * n * cnt * e : f; 
        int mid = (l + r) / 2; 
        long long ans = cnt ? 1LL * n * cnt * e : f;
        return min(ans, rec(s, l, mid, e, f) + rec(s, mid + 1, r, e, f));
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        int cnt = 0, n = s.size(); pre.resize(n);
        for(int i = 0; i < n; i++) pre[i] = cnt += (s[i] == '1');
        return rec(s, 0, n - 1, encCost, flatCost);
    }
};