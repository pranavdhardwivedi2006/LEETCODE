#include <bits/stdc++.h>
using namespace std;

class vals {
  public:
    int cnt;
    char l, r;
    vals() {cnt = 0; l = r = '0';}
    vals(int cnt, char l, char r) {
        this -> cnt = cnt;
        this -> l = l;
        this -> r = r;
    }
};

class segTree {
  public:
    vector<vals> arr; int n;
    segTree(int size) {
        n = size;
        arr.resize(n * 4);
    }
    void build(string& s, int node, int start, int end) {
        if(start == end) arr[node] = vals(1, s[end], s[end]);
        else {
            int mid = start + (end - start) / 2;
            build(s, 2 * node, start, mid);
            build(s, 2 * node + 1, mid + 1, end);
            char right = arr[2*node].r;
            char left = arr[2*node+1].l;
            int cnt = arr[2*node].cnt + arr[2*node+1].cnt - (left == right);
            arr[node] = vals(cnt, arr[2*node].l, arr[2*node+1].r);
        }
    }
    int query(string& s, int node, int start, int end, int l, int r) {
        if(r < start || l > end) return 0;
        else if(l <= start && end <= r) return arr[node].cnt;
        int mid = start + (end - start) / 2;
        int cnt = query(s, 2 * node, start, mid, l, r);
        cnt += query(s, 2 * node + 1, mid + 1, end, l, r);
        if (l <= mid && r > mid && s[mid] == s[mid + 1]) cnt--;
        return cnt;
    }
    void update(int node, int start, int end, int idx) {
        if(start == end) {
            char c = arr[node].l;
            c = c == 'A' ? 'B' : 'A';
            arr[node].l = arr[node].r = c;
            return ;
        }
        int mid = start + (end - start) / 2;
        if(idx <= mid) update(2 * node, start, mid, idx);
        else update(2 * node + 1, mid + 1, end, idx);
        char right = arr[2*node].r;
        char left = arr[2*node+1].l;
        int cnt = arr[2*node].cnt + arr[2*node+1].cnt;
        if(left == right) cnt--;
        arr[node].cnt = cnt;
        arr[node].l = arr[2*node].l;
        arr[node].r = arr[2*node+1].r;
    }
};

class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size(); segTree seg(n);
        vector<int> ans;
        seg.build(s, 1, 0, n - 1);
        for(auto& it : queries) {
            if(it[0] == 1) {
                seg.update(1, 0, n - 1, it[1]);
                s[it[1]] = s[it[1]] == 'A' ? 'B' : 'A';
            }
            else ans.push_back(it[2] - it[1] + 1 - seg.query(s, 1, 0, n - 1, it[1], it[2]));
        }
        return ans;
    }
};