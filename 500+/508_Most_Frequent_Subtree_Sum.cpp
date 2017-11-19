/* 508. Most Frequent Subtree Sum
 * Using a hashmap to record frequency of all sumtree sum
 * Find the max frequency and put all maxFreq's subsum into the result
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
    unordered_map<int, int> mp;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverseTree(root);
        vector<int> res;
        if(!root) return res;
        
        int mxFreq = INT_MIN;
        for(auto& p: mp){
            mxFreq = max(mxFreq, p.second);
        }
        
        for(auto& p: mp){
            if(mxFreq == p.second) res.push_back(p.first);
        }
        return res;
    }
    
    int traverseTree(TreeNode* node){
        if(!node) return 0;
        
        int left = traverseTree(node->left);
        int right = traverseTree(node->right);
        mp[left+right+node->val]++;
        return left+right+node->val;
    }
};