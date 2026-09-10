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
tuple<int, int, int> find(TreeNode* node) {
    if(!node) return {0, 0, 0};
    auto [lc, ls, lans] = find(node -> left);
    auto [rc, rs, rans] = find(node -> right);
    int sum = ls + rs + node -> val;
    int cnt = lc + rc + 1;
    int avg = sum / cnt;
    return {cnt, sum, (avg == node -> val) + lans + rans};
}
public:
    int averageOfSubtree(TreeNode* root) {
        return get<2>(find(root));
    }
};