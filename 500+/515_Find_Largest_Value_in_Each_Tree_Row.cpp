/* 515. Find Largest Value in Each Tree Row
 * A strightforward tree traversal. Each recursion we pass down the current level,
 * which is row of the node, indicates its position of the result array. Continually 
 * updating the result array to find the largest value in each tree level(row)
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
    
    void helper(TreeNode* node, int lvl, vector<int>& ans){
        if(node == nullptr) return;
        
        if(lvl >= ans.size()) ans.push_back(node->val);
        else ans[lvl] = max(ans[lvl], node->val);
        
        helper(node->left, lvl+1, ans);
        helper(node->right, lvl+1, ans);
    }
};