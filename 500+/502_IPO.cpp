/* 502. IPO
 * Greedy algorithm,
 * Split all capitals into two sets, doable & undoable
 * Every time we pick in the doable set which has most profit, and then move 
 * capitals in undoable set to doable set
 */


class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> doable;
        multiset<pair<int, int>> undoable;
        
        for(int i = 0; i < Profits.size(); i++){
            if(Profits[i] > 0){
                if(Capital[i] <= W){
                    doable.push(Profits[i]);
                }else{
                    undoable.emplace(Capital[i], Profits[i]);
                }
            }
        }
        
        while(k-- && doable.size()){
            W += doable.top();
            doable.pop();
            for(auto it = begin(undoable); undoable.size() > 0 && it->first <= W; it = undoable.erase(it)){
                doable.push(it->second);
            }
        }
        return W;
    }
};