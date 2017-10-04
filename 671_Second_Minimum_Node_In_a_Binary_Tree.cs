/* 671. Second Minimum Node In a Binary Tree
 * recursively checking the left and right children and determine what value needs to return
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
    public int FindSecondMinimumValue(TreeNode root) {
        if(root == null || root.left == null) return -1;
        
        if(root.left.val == root.val && root.right.val == root.val){
            int l = FindSecondMinimumValue(root.left);
            int r = FindSecondMinimumValue(root.right);
            
            if(l != -1 && r != -1) return Math.Min(l, r);
            if(l == -1) return r;
            return l;
        }else if(root.left.val == root.val){
            int l = FindSecondMinimumValue(root.left);
            if(l == -1) return root.right.val;
            else return Math.Min(l, root.right.val);
        }else if(root.right.val == root.val){
            int r = FindSecondMinimumValue(root.right);
            if(r == -1) return root.left.val;
            else return Math.Min(r, root.left.val);
        }else{
            return Math.Min(root.left.val, root.right.val);
        }
    }
}