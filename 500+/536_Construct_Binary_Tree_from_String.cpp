/* 536. Construct Binary Tree from String
 * parse string and construct the tree from left to right
 * increasing the index 'pos' to parse the string
 * Caculate each node by checking the next character behind it
 * If there is a ')', then the node don't have child
 * If there is a '(', then the node have child
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
    TreeNode* str2tree(string s) {
        int p = 0;
        return constructTree(s, p);
    }
    
    TreeNode* constructTree(string& str, int& pos){
        if(pos >= str.length()) return nullptr;
        
        int sign = 1;
        if(str[pos] == '-') { pos++; sign = -1; }
        int num = 0;
        while(isdigit(str[pos])){
            num *= 10;
            num += str[pos] - '0';
            pos++;
        }
        TreeNode* node = new TreeNode(sign*num);
        // dont have child
        if(pos >= str.length() || str[pos] == ')'){
            pos++;
            return node;
        }
        
        // skip '('
        pos++;
        node->left = constructTree(str, pos);
        // dont have right child
        if(pos >= str.length() || str[pos] == ')'){
            pos++;
            return node;
        }
        
        // skip '('
        pos++;
        node->right = constructTree(str, pos);
        
        // skip ')'
        pos++;
        return node;
    }
};