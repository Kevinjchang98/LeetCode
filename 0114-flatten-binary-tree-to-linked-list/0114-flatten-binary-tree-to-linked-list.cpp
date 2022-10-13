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
    void flatten(TreeNode* root) {
        if (!root) return;
            
        vector<TreeNode*> q;
        
        pre(root, q);
        
        for (int i = 0; i < q.size() - 1; i++) {
            q[i]->left = nullptr;
            q[i]->right = q[i + 1];
        }
    }
    
    void pre(TreeNode* root, vector<TreeNode*>& q) {
        if (!root)
            return;
        
        q.push_back(root);
        
        pre(root->left, q);
        pre(root->right, q);
    }
};