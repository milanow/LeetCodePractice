/* 450. Delete Node in a BST
 * After deletion, the node should be replace by the nearest node among its left/right children
 * Here we choose right children first, because original problem is okay with two conditions.
 * Then how to find the replaced node/value? Supposing it is called target node,
 * First is to find out where is the key node, simply doing a binary traverse.
 * Secondly, when meeting key node, we need to find out the nearest node in its right branch
 * which is the left most node in its right branch, then swap current value with target value
 * In the end, deleting that swapped node by going deeper recursion.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        
        if(root->val == key){
            // replace current node with its left child
            if(!root->right) return root->left;
            else{
                TreeNode* n = root->right;
                while(n->left) n = n->left;
                swap(n->val, root->val);
                
                root->right = deleteNode(root->right, key);
                return root;
            }
        }
        
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};