/* 444. Sequence Reconstruction
 * A topology sort problem. Counting from the last node in org, for each node in org, 
 * there shouldn't be any nodes pointing the nodes after current node
 * Also, if any node has no other node pointing to it before its previous node reached in org
 * (in the code, degree vector is used to keep this piece of information)
 * It proves that the path is not unique because it means there exist uncertainty.
 */

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.size() == 0) return false;
        unordered_map<int, unordered_set<int>> graph;
        int n = org.size(), cnt = 0;
        vector<int> degree(n+1, 0);
        for(auto& seq: seqs){
            for(int i = seq.size()-1; i >= 0; i--){
                if(seq[i] > n || seq[i] < 1) return false;
                if(i > 0 && graph[seq[i]].find(seq[i-1]) == graph[seq[i]].end()){
                    graph[seq[i]].insert(seq[i-1]);
                    if(degree[seq[i-1]]++ == 0) cnt++;
                }
                if(i == 0 && graph.find(seq[i]) == graph.end()){
                    graph.insert({seq[i], unordered_set<int>()});
                }
            }
        }
        if(n != graph.size()) return false;
        
        // all nodes except for last node should have some nodes behind pointing to it
        if(cnt != n-1) return false;
        for(int i = n-1; i >= 0; i--){
            // making sure there is no nodes before current node pointing to current node
            if(degree[org[i]] > 0) return false;
            for(int adj: graph[org[i]]){
                // Making sure the path is unique
                if(--degree[adj] == 0 && i > 0 && adj != org[i-1]) return false;
            }
        }
        return true;
    }
};