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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> children;
        TreeNode* root = nullptr;
        for(auto& it : descriptions) {
            TreeNode *par, *child;
            if(mpp.find(it[0]) != mpp.end()) {
                par = mpp[it[0]];
            } else {
                mpp[it[0]] = par = new TreeNode(it[0]);
            }
            if(mpp.find(it[1]) != mpp.end()) {
                child = mpp[it[1]];
                children.insert(it[1]);
            } else {
                mpp[it[1]] = child = new TreeNode(it[1]);
                children.insert(it[1]);
            }
            if(it[2]) par -> left = child;
            else par -> right = child;
            if(!root || child == root) root = par;
        }
        for(auto& it : descriptions) {
            if(!children.count(it[0])) return mpp[it[0]];
        }
        return root;
    }
};