struct info {
    unordered_map<long long, int> mp;
    long long comp = 0;
};

class SD {
public:
    int size, blocks;
    vector<long long> temp;
    vector<info> tree;

    SD(int n, vector<int>& arr) {
        size = sqrt(n);
        blocks = n / size + 1;
        tree.resize(blocks);
        temp = vector<long long>(arr.begin(), arr.end());
    }

    void build() {
        int n = temp.size();
        for(int i = 0; i < n; i++) {
            tree[i/size].mp[temp[i]]++;
        }
    }

    void update(int ql, int qr, int add) {
        for(int k = ql / size; k <= qr / size; k++) {
            int l = k * size;
            int r = (k + 1) * size - 1;
            if(l >= ql && r <= qr) tree[k].comp += add;
            else {
                l = max(l, ql); r = min(r, qr);
                for(int i = l; i <= r; i++) {
                    if(tree[k].mp[temp[i]] > 1) {
                        tree[k].mp[temp[i]]--;
                    } else {
                        tree[k].mp.erase(temp[i]);
                    }
                    temp[i] += add;
                    tree[k].mp[temp[i]]++;
                }
            }
        }
    }

    int query(int tsum, int num) {
        int ans = 0;
        for(int i = 0; i < blocks; i++) {
            long long req = 1LL * tsum - num - tree[i].comp;
            auto it = tree[i].mp.find(req);
            if(it != tree[i].mp.end()) {
                ans += it -> second;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums2.size();
        SD sd(n, nums2);
        sd.build();
        vector<int> ans;
        for(auto& it : queries) {
            if(it[0] == 1) {
                sd.update(it[1], it[2], it[3]);
            } else {
                int freq = 0;
                for(auto x : nums1) {
                    freq += sd.query(it[1], x);
                }
                ans.push_back(freq);
            }
        }
        return ans;
    }
};