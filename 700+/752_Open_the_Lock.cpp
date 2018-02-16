/* 752. Open the Lock
 * A typical BFS solution. Imagine there is a graph contain 10*10*10*10 nodes
 * representing the 4-digits keyword. Each nodes have 8 neighbors, which are got by 
 * individually rotating one specific whell by 1 (1 move). All deadends are those nodes
 * cannot be reached. Using BFSto find a shortest path to the target
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dict(begin(deadends), end(deadends));
        unordered_set<string> visited;
        
        queue<string> q;
        string start = "0000";
        q.push(start);
        if(dict.find(start) != dict.end()) return -1;
        int res = 0;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string node = q.front();
                q.pop();
                auto adj = findAdjs(node);
                for(string n: adj){
                    if(n == target) return ++res;
                    if(visited.find(n) != visited.end()) continue;
                    if(dict.find(n) == dict.end()){
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }
            res++;
        }
        return -1;
    }
    
private:
    vector<string> findAdjs(string key){
        vector<string> adjs;
        for(int i = 0; i < 4; i++){
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            adjs.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            adjs.push_back(tmp);
        }
        return adjs;
    }
};