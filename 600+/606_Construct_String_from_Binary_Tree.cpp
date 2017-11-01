/* 606. Construct String from Binary Tree
 * note: the '()' brackets can be added at parent root
 * say we have 1,2,3 where 1->left == 2, 1->right == 3,
 * the result should be 1(2)(3), the returned resursive method should
 * not include '()' of 2 & 3, I mean it should be
 * return node->val + '(' + returned 2 + ')' + '(' + returned 3 + ')'
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
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string s = to_string(t->val);
        if(t->left) s += '(' + tree2str(t->left) + ')';
        else if(t->right) s += "()";
        if(t->right) s += '(' + tree2str(t->right) + ')';
        return s;
    }
};