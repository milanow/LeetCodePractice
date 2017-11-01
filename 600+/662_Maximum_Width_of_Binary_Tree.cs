/* 662. Maximum Width of Binary Tree
 * use a List<SortedSet<int>> to track all nodes' positions according to depth
 * positions are value from 1 to 2^depth
 * Then iterating each levels to find out the max length
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
    public int WidthOfBinaryTree(TreeNode root) {
        var data = new List<SortedSet<int>>();
        helper(root, 0, 1, data);
        int mxLen = 0;
        for(int i = 0; i < data.Count; ++i){
            mxLen = Math.Max(data[i].Max - data[i].Min + 1, mxLen);
        }
        return mxLen;
    }
    
    private void helper(TreeNode node, int lvl, int pos, IList<SortedSet<int>> data){
        if(node == null) return;
        
        if(lvl >= data.Count){
            data.Add(new SortedSet<int>());
        }
        data[lvl].Add(pos);
        helper(node.left, lvl+1, pos*2-1, data);
        helper(node.right, lvl+1, pos*2, data);
    }
}