/* 563. Binary Tree Tilt
 * When talking about tree problem, the key is to find out: what information does children
 * need to pass/return to its parent. In this problem, we need to return the sum of child node
 * Because parent doen't care about tilt of its child, it only cares the sum of child such that
 * it can use to calculate tilt of its own tree.
 * Thus tilt sum can be set outside the recursion, which is "int tilt"
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
    int tilt;
public:
    int findTilt(TreeNode* root) {
        tilt = 0;
        nodeSum(root);
        return tilt;
    }
    
    int nodeSum(TreeNode* node){
        if(!node) return 0;
        
        int leftSum = nodeSum(node->left);
        int rightSum = nodeSum(node->right);
        tilt += abs(leftSum - rightSum);
        
        return node->val + leftSum + rightSum;
    }
};