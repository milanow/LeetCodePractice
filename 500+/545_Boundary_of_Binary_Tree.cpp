/* 545. Boundary of Binary Tree
 * The defination of boundary is important:
 * 1.Left Boundary is defined as the path from root to the left-most node, so as right boundary
 * 2.Any leaf should be considered as boundary, left/right most node of leftboundary/rightboundary is also leaf
 * Such that in each iteration, we save it to final result as long as it is leaf
 * Then consider how to determine if it belongs to boundary
 * The answer is before we found the left/right most node, all nodes traversed
 * should be boundary. So if we haven't found left/right most node, we add current node
 * The last thing is to care about the traverse sequence,
 * obviously, leftSubtree of root should check its left child first to find left most node
 * so does rightSubtree
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> v1, v2;
        if(!root) return v1;
        
        bool foundLeft = false, foundRight = false;
        if(root->left) calculateLeft(root->left, v1, foundLeft);
        if(root->right) calculateRight(root->right, v2, foundRight);
        v1.insert(begin(v1), root->val);
        v1.insert(end(v1), rbegin(v2), rend(v2));
        return v1;
    }
    
    void calculateLeft(TreeNode* node, vector<int>& lvec, bool& isFound){
        if(!node->left && !node->right){
            lvec.push_back(node->val);
            isFound = true;
            return;
        }
        
        if(node->left){
            if(!isFound) lvec.push_back(node->val);
            calculateLeft(node->left, lvec, isFound);
        }
        
        if(node->right){
            if(!node->left & !isFound) lvec.push_back(node->val);
            calculateLeft(node->right, lvec, isFound);
        }
    }
    
    void calculateRight(TreeNode* node, vector<int>& rvec, bool& isFound){
        if(!node->left && !node->right){
            rvec.push_back(node->val);
            isFound = true;
            return;
        }
        
        if(node->right){
            if(!isFound) rvec.push_back(node->val);
            calculateRight(node->right, rvec, isFound);
        }
        
        if(node->left){
            if(!node->right && !isFound) rvec.push_back(node->val); 
            calculateRight(node->left, rvec, isFound);
        }
    }
};