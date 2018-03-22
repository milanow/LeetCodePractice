/* 449. Serialize and Deserialize BST
 * One important thing in this problem is "BST", which means we could use value comparison
 * to determine if one node is left/right child of another node.
 * Serialization is making up a string with pre-order traversal,
 * deserilization firstly consruct node it self, then passing the range of min and max
 * to its children to see if value is its left/right children.
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
class Codec {
public:
    
    void preorderTree(TreeNode* node, string& str){
        if(!node) return;
        char buf[4];
        memcpy(buf, &(node->val), sizeof(int));
        for(int i = 0; i < 4; i++) str.push_back(buf[i]);
        preorderTree(node->left, str);
        preorderTree(node->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        preorderTree(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return inorderRec(data, pos, INT_MIN, INT_MAX);
    }
    
    TreeNode* preorderRec(string& str, int& pos, int mn, int mx){
        if(pos == str.length()) return nullptr;
        
        int value;
        memcpy(&value, &(str[pos]), sizeof(int));
        if(value < mn || value > mx) return nullptr;
        
        TreeNode* newNode = new TreeNode(value);
        pos += sizeof(int);
        newNode->left = inorderRec(str, pos, mn, value);
        newNode->right = inorderRec(str, pos, value, mx);
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));