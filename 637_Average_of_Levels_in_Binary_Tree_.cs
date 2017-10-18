/* 637. Average of Levels in Binary Tree
 * two list seperately record the sum & count of current level's info
 * got averages via sum[i]/count[i] per level
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
    public IList<double> AverageOfLevels(TreeNode root) {
        var sums = new List<double>();
        var counts = new List<int>();
        
        CollectInfoHelper(sums, counts, root, 0);
        for(int i = 0; i < sums.Count; ++i){
            sums[i] /= counts[i];
        }
        return sums;
    }
    
    private void CollectInfoHelper(List<double> sums, List<int> counts, TreeNode node, int level){
        if(node == null) return;
        
        if(level >= sums.Count){
            sums.Add(node.val);
            counts.Add(1);
        }else{
            sums[level] += node.val;
            counts[level]++;
        }
        
        CollectInfoHelper(sums, counts, node.left, level+1);
        CollectInfoHelper(sums, counts, node.right, level+1);
    }
}