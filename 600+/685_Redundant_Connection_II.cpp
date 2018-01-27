/* 685. Redundant Connection II
 * There are two considtions that may cause the tree invalid:
 * 1. a node has two parents
 * 2. a cycle detected
 * However, there might be a chance that these two conditions happens together
 * The algorithm's first part is to find potential answers causing first considtion,
 * second part is to find out if there is a cycle.
 * Detailed explaination can be found at comments below
 */

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // candA & candB represents two edges that have same child, which means it is invalid (a node can only have on parent)
        // candA is prior to candB in edges
        vector<int> parent(n+1, 0);
        vector<int> candA, candB;
        
        for(auto& edge: edges){
            if(parent[edge[1]] == 0){
                parent[edge[1]] = edge[0];
            }else{
                candA = vector<int>{parent[edge[1]], edge[1]};
                candB = edge;
                // make the tree valid, because all input's node value range from 1 to N
                edge[1] = 0;
            }
        }
        
        for (int i = 1; i <= n; i++) parent[i] = i;
        for(auto& edge: edges){
            if(edge[1] == 0) continue;
            int p1 = edge[0], p2 = edge[1], pp2 = root(parent, p1);
            // a cycle detected
            if(pp2 == p2){
                // there is a chance that cycle and two-parents node happends together
                // in this case, return the prior edge causes two-parents condition
                if(candA.empty()) return edge;
                return candA;
            }
            parent[p2] = pp2;
        }
        return candB;
    }
    
private:
    int root(vector<int>& parent, int k){
        while(parent[k] != k){
            k = parent[k] = parent[parent[k]];
        }
        return k;
    }    
};