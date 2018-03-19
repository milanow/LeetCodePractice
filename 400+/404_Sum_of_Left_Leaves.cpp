/* 404. Sum of Left Leaves
 * A left leave has two properties:
 * 1. no left or right child
 * 2. parent's left branch
 * Checking node->left and node->right we can know 1
 * Passing a bool value indicating if the node is parent's left child we can know 2
 * The last thing to do is just sum up these nodes' values
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
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        calSum(root, false);
        return sum;
    }
    
    void calSum(TreeNode* node, bool qualified){
        if(!node) return;
        
        if(qualified && !node->left && !node->right){
            sum += node->val;
            return;
        }
        
        calSum(node->left, true);
        calSum(node->right, false);
    }
};