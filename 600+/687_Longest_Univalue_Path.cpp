/* 687. Longest Univalue Path
 * For one node (included in univalue path), the univalue path can be formed by
 * 1) leftchild -> node -> rightchild
 * 2) leftchild/rightcild -> node -> node's parent
 * Thus for a specific recursion, we need to check
 * 1) longest univalue path inside left/right subtree
 * 2) longest univalue path "pass up" to node through its left/right child
 * The return value of helper() represents the longer value of 2)
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
    int longestUnivaluePath(TreeNode* root) {
        int mx = 0;
        if(root) helper(root, mx);
        return mx;
    }
    
private:
    int helper(TreeNode* node, int& mx){
        int l1 = node->left? helper(node->left, mx): 0;
        int r1 = node->right? helper(node->right, mx): 0;
        int l2 = node->left && node->left->val == node->val? l1+1: 0;
        int r2 = node->right && node->right->val == node->val? r1+1: 0;
        mx = max(l2+r2, mx);
        return max(l2, r2);
    }
};