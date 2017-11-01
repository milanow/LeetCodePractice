/* 653. Two Sum IV - Input is a BST
 * Use a hashset to remember all the differences(target-nodeValue) from Inorder Traversal of the tree
 * Whenever found it the current node.value exists in the hashset, return true;
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool FindTarget(TreeNode root, int k) {
        var stk = new Stack<TreeNode>();
        TreeNode cur = root;
        
        var map = new HashSet<int>();
        while(cur != null || stk.Count != 0){
            if(cur != null){
                stk.Push(cur);
                cur = cur.left;
            }else{
                TreeNode node = stk.Pop();
                if(map.Contains(node.val)) return true;
                map.Add(k - node.val);
                cur = node.right;
            }
        }
        return false;
    }
}