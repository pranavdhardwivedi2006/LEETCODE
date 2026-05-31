class SegTree {
    vector<int> tree, lazy;
public:
    SegTree(int n) {
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    int build(int node, int l, int r) {
        if (l == r) return tree[node] = l;
        int mid = (l + r) >> 1;
        int x = build(2 * node, l, mid);
        int y = build(2 * node + 1, mid + 1, r);
        return tree[node] = max(x, y);
    }

    void push(int node, int l, int r) {
        if (!lazy[node]) return;
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        tree[node] -= lazy[node];
        lazy[node] = 0;
    }

    int query(int node, int l, int r, int q) {
        push(node, l, r);
        if (l > q) return 0;
        if (r <= q) return tree[node];
        int mid = (l + r) >> 1;
        int x = query(2 * node, l, mid, q);
        int y = query(2 * node + 1, mid + 1, r, q);
        return max(x, y);
    }

    void update(int node, int l, int r, int ql, int qr, int sub) {
        push(node, l, r);
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr) {
            lazy[node] += sub;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(node * 2, l, mid, ql, qr, sub);
        update(node * 2 + 1, mid + 1, r, ql, qr, sub);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = min(150000, (int)queries.size() * 3);
        SegTree seg(n + 1); seg.build(1, 0, n);
        set<int> obs; obs.insert(0); obs.insert(n + 1);
        for (auto& it : queries) {
            if (it[0] == 1) {
                int x = it[1];
                auto r = obs.upper_bound(x);
                int nr = *r, pr = *prev(r);
                seg.update(1, 0, n, x + 1, nr, x - pr);
                obs.insert(x);
            } else {
                int maxi = seg.query(1, 0, n, it[1]);
                if (maxi >= it[2]) ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};