/* 652. Find Duplicate Subtrees
 * The idea is to serialize each subtrees. Since different serialization of tree is unique, thus we
 * can check if there exist multiple subtree that has same serilization.
 * The solution use a dictionary to record all trees' serialization results and its head
 * After serilization this whole tree, dive into each serilization string to see if duplicated serilaization
 * result exists and add the tree node to final result list
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
    public IList<TreeNode> FindDuplicateSubtrees(TreeNode root) {
        var dict = new Dictionary<string, List<TreeNode>>();
        SerializeTree(root, dict);
        var ans = new List<TreeNode>();
        foreach(string s in dict.Keys){
            if(dict[s].Count > 1){
                ans.Add(dict[s][0]);
            }
        }
        return ans;
        
    }
    
    private string SerializeTree(TreeNode node, Dictionary<string, List<TreeNode>> dict){
        if(node == null) return "";
        string res = '(' + SerializeTree(node.left, dict) + node.val.ToString() + SerializeTree(node.right, dict) + ')';
        if(!dict.ContainsKey(res)){
            dict.Add(res, new List<TreeNode>());
        }
        dict[res].Add(node);
        return res;
    }
}