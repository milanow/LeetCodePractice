/* 623. Add One Row to Tree
 * With different value of depth, node should be added differently
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) return nullptr;
        
        if(d == 1){
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }else if(d == 2){
            TreeNode* nodeleft = new TreeNode(v);
            TreeNode* noderight = new TreeNode(v);
            nodeleft->left = root->left;
            noderight->right = root->right;
            root->left = nodeleft;
            root->right = noderight;
            return root;
        }else{
            root->left = addOneRow(root->left, v, d-1);
            root->right = addOneRow(root->right, v, d-1);
            return root;
        }
    }
};