/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> prev;
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            prev.clear(); int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                prev.push_back(node);
                if(node -> left) {
                    q.push(node -> left);
                    parent[node -> left] = node;
                }
                if(node -> right) {
                    q.push(node -> right);
                    parent[node -> right] = node;
                }
            }
        }
        unordered_set<TreeNode*> st;
        for(auto it : prev) st.insert(it);
        while(st.size() > 1) {
            unordered_set<TreeNode*> st1;
            for(auto& it : st) st1.insert(parent[it]);
            st = st1;
        }
        return *(st.begin());
    }
};