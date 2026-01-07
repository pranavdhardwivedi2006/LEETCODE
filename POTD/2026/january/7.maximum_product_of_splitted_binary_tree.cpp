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
int sum = 0;
long long maxi = 0; 
int MOD = 1e9 + 7;
private:
    void find(TreeNode* root) {
        if(!root) return ; sum += root -> val; 
        find(root -> left); find(root -> right);
    }
    long long calc(TreeNode* root) {
        if(!root) return 0;
        long long left = calc(root -> left);
        long long right = calc(root -> right);
        maxi = max(maxi, left * (sum - left));
        maxi = max(maxi, right * (sum - right));
        return left + right + root -> val;
    }
public:
    int maxProduct(TreeNode* root) {
        find(root); calc(root);
        return maxi % MOD;
    }
};