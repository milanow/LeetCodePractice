/* 802. Find Eventual Safe States
 * The target of the problem is actually finding all cycle elements inside a directed graph
 * By marking a node 1, we say this node is visited, by marking a node -1, mean this node
 * is in a searching branch, if any node is "deeper" than (because we are dfs-ing) this -1 node
 * can points to the node, then we detect a cycle.
 */ 

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res, visited(n, 0);
        for(int i = 0; i < n; i++){
            if(dfs(graph, visited, i)) res.push_back(i);
        }
        return res;
        
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node){
        if(visited[node]) return visited[node] == 1;
        
        visited[node] = -1;
        for(auto adj: graph[node]){
            if(!dfs(graph, visited, adj)) return false;
        }
        visited[node] = 1;
        return true;
    }
};