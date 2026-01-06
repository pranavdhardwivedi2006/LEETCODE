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
    int maxLevelSum(TreeNode* root) {
        int level = 1, ans = 1, maxi = INT_MIN;
        queue<TreeNode*> q;
        q.push(root); 
        while(!q.empty()) {
            int n = q.size(), curr = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* temp = q.front(); q.pop();
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                curr += temp -> val;
            }
            if(maxi < curr) {
                maxi = curr;
                ans = level;
            }
            level++;
        } 
        return ans;
    }
};