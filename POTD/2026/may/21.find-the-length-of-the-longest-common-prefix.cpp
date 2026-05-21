struct Node {
    Node* links[10];
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int n) {
        string s = to_string(n);
        Node* node = root;
        for(auto it : s) {
            if(!node -> links[it-'0']) {
                node -> links[it-'0'] = new Node();
            }
            node = node -> links[it-'0'];
        }
    }

    int longestPrefix(int n) {
        string s = to_string(n);
        Node* node = root; 
        int ans = 0;
        for(auto it : s) {
            if(!node -> links[it-'0']) break;
            node = node -> links[it-'0'];
            ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(auto it : arr1) {
            trie.insert(it);
        }
        int ans = 0;
        for(auto it : arr2) {
            ans = max(ans, trie.longestPrefix(it));
        }
        return ans;
    }
};