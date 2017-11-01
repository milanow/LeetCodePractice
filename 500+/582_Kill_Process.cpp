/* 582. Kill Process
 * A typical graph problem, saving the tree as a DAG(Directed Asyclic Graph)
 * BFS to traversal the graph and save it to vector.
 */

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, unordered_set<int>> graph;
        for(int i = 0; i < pid.size(); ++i){
            graph[ppid[i]].insert(pid[i]);
        }
        
        vector<int> ans;
        queue<int> q;
        q.push(kill);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            if(graph.find(node) != graph.end()){
                for(int n: graph[node]){
                    q.push(n);
                }
            }
        }
        return ans;
    }
    
    
};