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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        
        if (root)
            ans++;    
        
        if (root->left)
            ans += helper(root->left, root->val);
        
        if (root->right)
            ans += helper(root->right, root->val);
        
        return ans;
    }
    
    int helper(TreeNode* root, int max) {
        if (!root)
            return 0;
        
        int ans = root->val >= max ? 1 : 0;
        
        return ans 
            + helper(root->left, std::max(root->val, max)) 
            + helper(root->right, std::max(root->val, max));
    }
};