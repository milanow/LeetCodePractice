/* 654. Maximum Binary Tree
 * Use a 'stack' to store the nodes who has possibility to be added as child or parent
 * eg, if[4,1,2,5], when reaches '5', then 4,1,2 do not need to exist in stack since 5 is 
 * guarentee to be parent of left subtree, that's why resize is called every iteration
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> s { new TreeNode(nums[0]) };
        for (int i = 1; i < nums.size(); ++i) {
            TreeNode* cur = new TreeNode(nums[i]);
            auto it = upper_bound(s.rbegin(), s.rend(), cur, 
                                  [](const TreeNode* a, const TreeNode* b) { return a->val < b->val; });            
            if (it != s.rend()) (*it)->right = cur;
            if (it != s.rbegin()) cur->left = *next(it, -1);
            s.resize(distance(it, s.rend()));
            s.push_back(cur);
        }
        return s.front();
    }
};