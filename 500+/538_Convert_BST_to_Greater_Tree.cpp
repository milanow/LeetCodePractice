/* 538. Convert BST to Greater Tree
 * Traverse the tree as right->parent->left order, where in a BST is traverse from big to small number
 * continually adding 'base' for each tree node as the addition for them to add to itself
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
    int base = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        toGreaterTree(root);
        return root;
    }
    
    void toGreaterTree(TreeNode* node){
        if(!node) return;
        
        toGreaterTree(node->right);
        int ori = node->val;
        node->val += base;
        base += ori;
        toGreaterTree(node->left);
    }
};