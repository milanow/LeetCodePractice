/* 572. Subtree of Another Tree
 * we only need to check the subtrees of source tree, whose depth is same with
 * target tree, to see wether it is same tree with target tree.
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
    vector<TreeNode*> nodes;
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        
        getDepth(s, getDepth(t, -1));
        
        for(auto n: nodes){
            if(isIdentical(n, t)) return true;
        }
        return false;
    }
    
    int getDepth(TreeNode* n, int d){
        if(!n) return -1;
        
        int depth = max(getDepth(n->left, d), getDepth(n->right, d)) + 1;
        
        if(depth == d){
            nodes.push_back(n);
        }
        
        return depth;
    }

    bool isIdentical(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2) return true;
        if(!n1 || !n2 || n1->val != n2->val) return false;
        
        return isIdentical(n1->left, n2->left) && isIdentical(n1->right, n2->right);
    }
    
};