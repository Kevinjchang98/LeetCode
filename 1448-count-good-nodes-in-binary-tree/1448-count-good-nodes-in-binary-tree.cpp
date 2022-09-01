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
        if (!root)
            return 0;
        
        return 1 
            + helper(root->left, root->val) 
            + helper(root->right, root->val);
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