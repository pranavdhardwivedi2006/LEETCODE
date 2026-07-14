const int MOD = 1e9 + 7;

class SegTree {
vector<pair<int, int>> tree; 
vector<int> powerof10;

public:
    SegTree(int n) {
        tree.resize(n * 4);
        powerof10.resize(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            powerof10[i] = 10LL * powerof10[i-1] % MOD;
        }
    };

    pair<int, int> build(int node, int l, int r, const string& s) {
        if(l == r) return tree[node] = {s[l] - '0', (s[l] - '0') != 0};
        int mid = (l + r) >> 1;
        auto [left, cnt1] = build(2 * node, l, mid, s);
        auto [right, cnt2] = build(2 * node + 1, mid + 1, r, s);
        int val = (1LL * left * powerof10[cnt2] % MOD + right) % MOD;
        return tree[node] = {val, cnt1 + cnt2};
    };

    pair<int, int> query(int node, int l, int r, int ql, int qr, int multiplier) {
        if(r < ql || l > qr) return {0, 0};
        if(ql <= l && qr >= r) return {1LL * tree[node].first * multiplier % MOD, tree[node].second};
        int mid = (l + r) >> 1;
        auto [left, cnt1] = query(2 * node, l, mid, ql, qr, multiplier);
        auto [right, cnt2] = query(2 * node + 1, mid + 1, r, ql, qr, multiplier);
        return {(1LL * left * powerof10[cnt2] % MOD + right) % MOD, cnt1 + cnt2};
    }
};

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), prev = 0, m = queries.size();
        vector<int> prefix(n), ans(m);
        for(int i = 0; i < n; i++) {
            prefix[i] = prev += s[i] - '0';
        }
        SegTree segtree(n);
        segtree.build(1, 0, n - 1, s);
        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            int multiplier = prefix[r] - (l ? prefix[l-1] : 0);
            ans[i] = segtree.query(1, 0, n - 1, l, r, multiplier).first;
        }
        return ans;
    }
};