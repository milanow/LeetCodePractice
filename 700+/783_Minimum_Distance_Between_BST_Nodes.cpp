/* 783. Minimum Distance Between BST Nodes
 * This is a BST, thus to find out the minimum distance, we just need to check
 * the difference of adjcent nodes to find out the minumum one.
 * Adjcent means parent->children
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
    int mn = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        helper(root);
        return mn;
    }
    
    pair<int, int> helper(TreeNode* node){ 
        // first == min, second == max
        pair<int, int> ans = {node->val, node->val};
        if(node->left){
            auto p = helper(node->left);
            ans.first = p.first;
            mn = min(node->val - p.second, mn);
        }
        
        if(node->right){
            auto p = helper(node->right);
            ans.second =p.second;
            mn = min(p.first - node->val, mn);
        }
        return ans;
    }
};