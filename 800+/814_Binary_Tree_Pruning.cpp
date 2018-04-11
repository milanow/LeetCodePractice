/* 814. Binary Tree Pruning
 * For each node, we have two scenario:
 * 1. node->value = 1, means this node doesn't need to be deleted
 * 2. node->value = 0, means this node is possible to be deleted,
 *    depends on if its children have at least one value '1'
 * Thus in each recursion, we need to return this node or nullptr
 * nullptr means that we have delete this node and all its branches
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return nullptr;
        
        if(root->val == 1){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            return root;
        }else{
            TreeNode* l = nullptr, *r = nullptr;
            l = pruneTree(root->left);
            r = pruneTree(root->right);
            if(!l && !r) return nullptr;
            
            root->left = l;
            root->right = r;
            return root;
        }
    }
};