#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<array<int, 6>> tree;
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }
    // Build the segment tree
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) tree[node][arr[start]]++;
        else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            for(int i = 0; i < 6; i++) {
                tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
            }
        }
    }
    // Query sum in range [l, r]
    int query(int node, int start, int end, int l, int r, int k) {
        if (r < start || end < l) return 0; // outside range
        if (l <= start && end <= r) return tree[node][k]; // completely inside
        int mid = (start + end) / 2;
        int leftSum = query(2 * node, start, mid, l, r, k);
        int rightSum = query(2 * node + 1, mid + 1, end, l, r, k);
        return leftSum + rightSum;
    }
    // Update value at index idx
    void update(int node, int start, int end, int idx, int val, int old) {
        if (start == end) {
            tree[node][val]++;
            tree[node][old]--;
        }
        else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val, old);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val, old);
            }
            for(int i = 0; i < 6; i++) {
                tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
            }
        }
    }
};

class Solution {
private:
    int bits(long long n) {
        if(n == 1) return 0;
        int cnt = 0;
        while(n) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        array<int, 51> arr;
        arr[0] = -1; arr[1] = 0;
        for(int i = 2; i < 51; i++) {
            int set = bits(i);
            arr[i] = arr[set] + 1;
        }
        vector<int> pop_trk; int n = nums.size();
        for(auto& it : nums) pop_trk.push_back(arr[bits(it)] + 1);
        SegmentTree seg(n); vector<int> ans;
        seg.build(pop_trk, 1, 0, n - 1);
        for(auto& it : queries) {
            if(it[0] == 1) ans.push_back(seg.query(1, 0, n - 1, it[1], it[2], it[3]));
            else {
                int prev = pop_trk[it[1]];
                pop_trk[it[1]] = arr[bits(it[2])] + 1;
                seg.update(1, 0, n - 1, it[1], pop_trk[it[1]], prev);
            }
        }
        return ans;
    }
};