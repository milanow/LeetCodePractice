/* 549. Binary Tree Longest Consecutive Sequence II
 * Possible longest consecutive reside int either: with current node or its children
 * l & r represent increasing & decreasing sequence containing current node
 * childmax is children's longrst consecutive sequence.
 * for each node with difference 1 or -1, we check if it can go deeper to get 
 * longer sequence with same difference (findPath()).
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
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int l = 0, r = 0, cur = 0, childmax = 0;
        l = findPath(root->left, root->val, 1) + findPath(root->right, root->val, -1) + 1;
        r = findPath(root->left, root->val, -1) + findPath(root->right, root->val, 1) + 1;
        cur = max(l, r);
        childmax = max(longestConsecutive(root->left), longestConsecutive(root->right));
        
        return max(cur, childmax);
    }
    
    int findPath(TreeNode* node, int parentval, int diff){
        if(!node) return 0;
        
        if(node->val == parentval + diff){
            return max(findPath(node->left, node->val, diff), findPath(node->right, node->val, diff)) + 1;
        }else return 0;
    }
};