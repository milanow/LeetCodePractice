/* 742. Closest Leaf in a Binary Tree
 * Treat the binary tree as regular graph, the closest leaf of a node is starting from the node
 * Using BFS to search the nearest node which has only one adjcent node. 
 * corner cases: it might be the root of tree that has only one child. Except this condition
 * we can return the qualified node.
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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        auto knode = makeGraph(graph, root, k);
        // knode itself is a leaf
        if(graph[knode].size() == 1 && knode != root) return knode->val;
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(knode);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            visited.insert(n);
            
            // if only has one adjacent node, and it is not root(because if root has one child, then it might be the closest leaf, however it is not a leaf)
            if(graph[n].size() == 1 && n != root) return n->val;
            for(auto child: graph[n]){
                if(visited.find(child) != visited.end()) continue;
                q.push(child);
            }
        }
        return k;
    }

private: 
    TreeNode* makeGraph(unordered_map<TreeNode*, vector<TreeNode*>>& graph, TreeNode* node, int k){
        if(!node) return nullptr;
        
        TreeNode* l = nullptr, *r = nullptr;
        if(node->left){
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);
            l = makeGraph(graph, node->left, k);
        }
        
        if(node->right){
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);
            r = makeGraph(graph, node->right, k);
        }
        if(node->val == k) return node;
        return l? l: r;
    }
};