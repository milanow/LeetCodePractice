/* 501. Find Mode in Binary Search Tree
 * Simply find that max frequency of the whole tree
 * Traverse second time to check wichi meets the max frequency
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
    vector<int> res;
public:
    vector<int> findMode(TreeNode* root) {
        int mfq, pre, cnt;
        getMaxFreq(root, mfq=0, pre=INT_MIN, cnt=0);
        getMode(root, mfq, pre, cnt=0);
        return res;
    }
    
    void getMaxFreq(TreeNode* r, int& mfq, int& pre, int& cnt) {
        if (!r) return;
        getMaxFreq(r->left, mfq, pre, cnt);
        ++(cnt*=(r->val==pre));
        getMaxFreq(r->right, mfq=max(mfq,cnt), pre=r->val, cnt);
    }
    
    void getMode(TreeNode* r, const int mfq, int& pre, int& cnt) {
      if (!r) return;
      getMode(r->left, mfq, pre, cnt);
      if (mfq == ++(cnt*=(r->val==pre))) res.push_back(r->val);
      getMode(r->right, mfq, pre=r->val, cnt);
    }
};