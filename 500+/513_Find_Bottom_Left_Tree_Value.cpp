/* 513. Find Bottom Left Tree Value
 * A possible leftmost bottom node is at least not left child or right child
 * Because if it has children, it won't be the bottom value
 * Traverse the tree and updating deeper leftmost value
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
    int curLevel = -1;
    int curVal = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        helper(root, 0);
        return curVal;
    }
    
    void helper(TreeNode* node, int level){
        // considered as a leftmost candidate
        if(!node->left && !node->right){
            if(level > curLevel){
                curLevel = level;
                curVal = node->val;
            }
            return;
        }
        
        if(node->left) helper(node->left, level+1);
        if(node->right) helper(node->right, level+1);
    }
};