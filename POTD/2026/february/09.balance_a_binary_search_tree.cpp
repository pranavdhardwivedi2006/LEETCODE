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
vector<int> arr;
private :
    void rec(TreeNode* root) {
        if(!root) return ;
        rec(root -> left);
        arr.push_back(root -> val);
        rec(root -> right);
    }
    TreeNode* build(int i, int j) {
        if(j < i) return NULL;
        if(i == j) return new TreeNode(arr[i]);
        int mid = (i + j) >> 1;
        TreeNode* root = new TreeNode(arr[mid]);
        root -> left = build(i, mid - 1);
        root -> right = build(mid + 1, j);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        rec(root); return build(0, arr.size() - 1);
    }
};