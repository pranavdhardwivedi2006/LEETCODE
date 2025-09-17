class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        TreeNode* root = new TreeNode();
        TreeNode* curr = root;
        unordered_map<TreeNode*, TreeNode*> mpp;
        int i = 0, n = s.size();
        int cnt = 0;
        while (i < n) {
            int num = 0;
            while (i < n && s[i] != '-') num = num * 10 + (s[i++] - '0');
            TreeNode* node = new TreeNode(num); mpp[node] = curr;
            if (!curr -> left) curr = curr -> left = node;
            else curr = curr -> right = node;
            int x = 0;
            while (i < n && s[i] == '-') x++, i++;
            while(cnt >= x) curr = mpp[curr], cnt--;
            cnt = x;
        }
        return root -> left;
    }
};