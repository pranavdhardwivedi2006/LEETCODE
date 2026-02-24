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
private:
    int rec(int x, TreeNode* root) {
        x <<= 1; x |= root -> val; int l = 0, r = 0;
        if(!root -> left && !root -> right) return x;
        if(root -> left) l = rec(x, root -> left);
        if(root -> right) r = rec(x, root -> right);
        return l + r;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return rec(0, root);
    }
};