/* 815. Bus Routes
 * A typical BFS solution, except that we don't need to visit the bus stops that we already visited
 * Because that may take extra buses, but we are finding the min number of buses we need to take
 */

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>> graphs;
        for(int i = 0; i < routes.size(); i++){
            for(auto& stop: routes[i]){
                graphs[stop].insert(i);
            }
        }
        
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        visited.insert(S);
        q.emplace(S, 0);
        while(!q.empty()){
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            
            if(node == T) return step;
            step++;
            for(int idx: graphs[node]){
                for(int adj: routes[idx]){
                    if(visited.find(adj) == visited.end()){
                        visited.insert(adj);
                        q.emplace(adj, step);
                    }
                }
            }
        }
        return -1;
    }
};