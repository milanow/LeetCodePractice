/* 684. Redundant Connection
 * A typical union-find solution. Iteratively connecting the nodes together
 * According to the defination of tree, if there is an edge who's two nodes
 * are already connected. Then this edge is redundant.
 * Since there is only one extra edge, we can return the result immediately when
 * we met such condition. And it will be the later answer even there might be 
 * multiple answers.
 */

public class Solution {
    public int[] FindRedundantConnection(int[,] edges) {
        int[] parent = new int[1001];
        for(int i = 0; i < 1001; ++i){
            parent[i] = i;
        }
        
        int[] res = {0, 0};
        for(int i = 0; i < edges.GetLength(0); ++i){
            int rootA = Root(parent, edges[i,0]), rootB = Root(parent, edges[i,1]);
            if(rootA == rootB){
                res[0] = edges[i,0];
                res[1] = edges[i,1];
                return res;
            }
            parent[rootA] = rootB;
        }
        return res;
    }
    
    private int Root(int[] parent, int k){
        while(parent[k] != k){
            // parent[k] = Root(parent, parent[k]);
            k = parent[k] = parent[parent[k]];
        }
        return parent[k];
    }
}