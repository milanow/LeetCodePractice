/* 776. Split BST
 * The key point of thie problem is "it is a BST", which means if a node is smaller
 * than 'V', then all nodes of its left subtree's values is smaller than 'V',
 * vice versa. 
 * Therefore when meeting a node, if it is larger than 'V', we don't need to care about
 * its right subtree. Instead we go deeper to its left subtree and do modification there.
 * a vector<TreeNode*>(2, nullptr) is where res[0] represents the small BST, res[1] represents
 * the large BST after spliting.
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> res(2, nullptr);
        if(!root) return res;
        
        if(root->val > V){
            res[1] = root;
            auto subres = splitBST(root->left, V);
            root->left = subres[1];
            res[0] = subres[0];
        }else{
            res[0] = root;
            auto subres = splitBST(root->right, V);
            root->right = subres[0];
            res[1] = subres[1];
        }
        return res;
    }
};