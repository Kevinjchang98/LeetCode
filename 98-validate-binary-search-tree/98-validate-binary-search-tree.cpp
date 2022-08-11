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
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        if (root) {
            if (!isValidBST(root->left))
                return false;

            if (!prev || (prev && prev->val < root->val)) {
                prev = root;
            } else {
                return false;
            }
            
            if (!isValidBST(root->right))
                return false;
        }
        
        return true;
    }
};