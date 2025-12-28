class Solution {
typedef long long ll;
vector<int> hi, lo; int n, off;
vector<vector<vector<vector<ll>>>> dp;
private:
    void build(ll num, vector<int>& a) {
        string s = to_string(num);
        for(char& c : s) a.push_back(c - '0');
    }
    ll rec(int odd, int even, int curr, bool l, bool h) {
        int diff = odd - even;
        if(curr > n) return !diff && even; diff += off;
        if(dp[curr-1][diff][l][h] != -1) return dp[curr-1][diff][l][h];
        int st = lo[curr-1], en = hi[curr-1]; ll ans = 0;
        if(!l && !h) {
            if(st == en) {
                (curr & 1) ? (odd += st) : (even += st);
                ans += rec(odd, even, curr + 1, l, h);
            }
            else {
                for(int i = st; i <= en; i++) {
                    int od = 0, ev = 0; (curr & 1) ? od += i : ev += i;
                    if(i == st) ans += rec(odd + od, even + ev, curr + 1, 0, 1);
                    else if(i == en) ans += rec(odd + od, even + ev, curr + 1, 1, 0);
                    else ans += rec(odd + od, even + ev, curr + 1, 1, 1);
                }
            }
        }
        else if(l && !h) {
            for(int i = 0; i <= en; i++) {
                int od = 0, ev = 0; (curr & 1) ? od += i : ev += i;
                if(i == en) ans += rec(odd + od, even + ev, curr + 1, 1, 0);
                else ans += rec(odd + od, even + ev, curr + 1, 1, 1);
            }
        }
        else if(h && !l) {
            for(int i = st; i <= 9; i++) {
                int od = 0, ev = 0; (curr & 1) ? od += i : ev += i;
                if(i == st) ans += rec(odd + od, even + ev, curr + 1, 0, 1);
                else ans += rec(odd + od, even + ev, curr + 1, 1, 1);
            }
        }
        else {
            for(int i = 0; i <= 9; i++) {
                int od = 0, ev = 0; (curr & 1) ? od += i : ev += i;
                ans += rec(odd + od, even + ev, curr + 1, 1, 1);
            }
        }
        return dp[curr-1][diff][l][h] = ans;
    }
public:
    ll countBalanced(ll low, ll high) {
        build(low, lo); build(high, hi); n = hi.size();
        while(lo.size() < hi.size()) lo.insert(lo.begin(), 0);
        int k = off = 9 * (n / 2 + n % 2) + 1;
        dp.resize(n,
            vector<vector<vector<ll>>>(2 * k + 1,
                vector<vector<ll>>(2, vector<ll>(2, -1))
            )
        );
        return rec(0, 0, 1, 0, 0);
    }
};©leetcode