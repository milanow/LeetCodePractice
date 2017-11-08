/* 530. Minimum Absolute Difference in BST
 * Save all nodes into an array (ordered set here) and sort it from small to large
 * The min diff can only resides between ajacent elements
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
    int getMinimumDifference(TreeNode* root) {
        set<int> st;
        helper(root, st);
        int prev = -1, mindiff = INT_MAX;
        for(int i: st){
            if(prev != -1){
                mindiff = min(mindiff, i - prev);
            }
            prev = i;
        }
        return mindiff;
    }
    
    void helper(TreeNode* node, set<int>& st){
        if(!node) return;
        
        st.insert(node->val);
        helper(node->left, st);
        helper(node->right, st);
    }
};