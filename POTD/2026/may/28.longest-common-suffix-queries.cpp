struct Node {
    int links[26] = {0};
    int len = INT_MAX;
    int index = INT_MAX;
};

class Trie {
    vector<Node> tree;
public:
    Trie() {
        tree.emplace_back();
    }


    void insert(string& s, int idx) {
        int curr = 0, n = s.size();
        auto update = [&](int node) {
            if(tree[node].len == n) {
                tree[node].index = min(tree[node].index, idx);
            } else if(tree[node].len > n) {
                tree[node].len = n;
                tree[node].index = idx;
            }
        };
        update(curr);
        for(int i = s.size() - 1; i >= 0; i--) {
            if(tree[curr].links[s[i]-'a'] == 0) {
                tree.emplace_back();
                tree[curr].links[s[i]-'a'] = tree.size() - 1;
            }
            curr = tree[curr].links[s[i]-'a'];
            update(curr);
        }                
    }

    int find(string& s) {
        int curr = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(tree[curr].links[s[i] - 'a'] == 0) break;
            curr = tree[curr].links[s[i]-'a'];
        }
        return tree[curr].index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        for(int i = 0; i < wordsContainer.size(); i++) {
            trie.insert(wordsContainer[i], i);
        }
        vector<int> ans(wordsQuery.size());
        for(int i = 0; i < wordsQuery.size(); i++) {
            ans[i] = trie.find(wordsQuery[i]);
        }
        return ans;
    }
};