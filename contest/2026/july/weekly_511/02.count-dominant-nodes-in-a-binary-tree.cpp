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
int ans = 0;
int rec(TreeNode* curr) {
    if(!curr) return 0;
    int left = rec(curr -> left);
    int right = rec(curr -> right);
    int maxi = max({left, right, curr -> val});
    if(curr -> val == maxi) ans++;
    return maxi;
}
public:
    int countDominantNodes(TreeNode* root) {
        rec(root); return ans;
    }
};