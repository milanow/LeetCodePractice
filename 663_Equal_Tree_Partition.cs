/* 663. Equal Tree Partition
 * Use a hashset to record all possible values of subtree except original tree (that's why
 * pass down a isRoot argument). And check if the set contains half sum of the whole tree
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
    public bool CheckEqualTree(TreeNode root) {
        var st = new HashSet<int>();
        int sum = CheckEqualTreeHelper(root, st, true);
        if(sum % 2 != 0) return false;
        else return st.Contains(sum/2);
    }
    
    private int CheckEqualTreeHelper(TreeNode node, HashSet<int> st, bool isRoot){
        if(node == null) return 0;
        
        int leftSum = CheckEqualTreeHelper(node.left, st, false);
        int rightSum = CheckEqualTreeHelper(node.right, st, false);
        
        int sum = leftSum + rightSum + node.val;
        if(!isRoot) st.Add(sum);
        return sum;
    }
}