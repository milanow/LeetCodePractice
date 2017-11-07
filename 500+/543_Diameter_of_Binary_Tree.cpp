/* 543. Diameter of Binary Tree
 * for each node, the longest path can only reside in two situations:
 * 1. path includes current node, then path = depth(leftnode) + depth(rightnode) + 1 - 1
 * 2. path doesn't include current node, then it resides in leftnode or rightnode
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = depthOfTree(root->left) + depthOfTree(root->right);     
        return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), res);
    }
    
    int depthOfTree(TreeNode* node){
        if(!node) return 0;        
        return max(depthOfTree(node->left), depthOfTree(node->right)) + 1;
    }
    
};