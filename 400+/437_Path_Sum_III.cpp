/* 437. Path Sum III
 * A back-tracking solution. Adding node's value to all possible sum in each iteration
 * After checking all children, delete node's value to all possible sum to make
 * the sums can be further used
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
    int paths = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> sums;
        helper(sums, root, sum);
        return paths;
    }
    
    void helper(vector<int>& sums, TreeNode* node, int tar){
        if(!node) return;
        sums.push_back(0);
        for(int i = 0; i < sums.size(); i++){
            if((sums[i] += node->val) == tar) paths++;
        }
        helper(sums, node->left, tar);
        helper(sums, node->right, tar);
        for(int i = 0; i < sums.size(); i++){
            sums[i] -= node->val;
        }
        sums.pop_back();
    }
};