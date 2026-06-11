class SegTree {
    vector<array<int, 2>> tree;
public:
    SegTree(int n) {
        tree.resize(n * 4);
    }

    void build(vector<int>& arr, int node, int l, int r) {
        if(l == r) {
            tree[node] = {arr[l], arr[r]}; 
            return ;
        }
        int mid = (l + r) >> 1;
        build(arr, 2 * node, l, mid);
        build(arr, 2 * node + 1, mid + 1, r);
        tree[node][0] = min(tree[node*2][0], tree[node*2+1][0]);
        tree[node][1] = max(tree[node*2][1], tree[node*2+1][1]);
    }

    array<int, 2> query(int node, int l, int r, int ql, int qr) {
        if(l > qr || r < ql) return {INT_MAX, INT_MIN};
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        auto it1 = query(node * 2, l, mid, ql, qr);
        auto it2 = query(node * 2 + 1, mid + 1, r, ql, qr);
        return {min(it1[0], it2[0]), max(it1[1], it2[1])};
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size(); SegTree segtree(n);
        segtree.build(nums, 1, 0, n - 1);
        using t = tuple<int, int, int>;
        priority_queue<t, vector<t>> pq;
        for(int i = 0; i < n - 1; i++) {
            auto it = segtree.query(1, 0, n - 1, i, n - 1);
            pq.push({it[1] - it[0], i, n - 1});
        }
        long long ans = 0;
        while(k-- && !pq.empty()) {
            auto [val, st, end] = pq.top(); pq.pop();
            ans += val;
            if(st < end - 1) {
                auto it = segtree.query(1, 0, n - 1, st, end - 1);
                pq.push({it[1] - it[0], st, end - 1});
            }
        }
        return ans;
    }
};