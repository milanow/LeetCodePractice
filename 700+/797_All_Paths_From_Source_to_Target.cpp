/* 797. All Paths From Source to Target
 * A typical dfs, don't even need to construct graph yourself.
 * try out every possible paths and to see if the path can reach n-1 node
 */

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> sols;
        vector<int> sol(1, 0);
        int n = graph.size();
        if(n == 0) return sols;
        dfs(graph, sols, sol, 0, n);
        return sols;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& sols, vector<int>& sol, int node, int n){
        if(node == n-1){
            sols.push_back(sol);
            return;
        }
        
        for(int adj: graph[node]){
            sol.push_back(adj);
            dfs(graph, sols, sol, adj, n);
            sol.pop_back();
        }
    }
};