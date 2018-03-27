/* 465. Optimal Account Balancing
 * First putting all ppl's debts in an array
 * debt[i] > 0 means someone needs to give other ppl money
 * debt[i] < 0 means someone needs to collect money from others
 * 
 * Secondly, we use back-tracking to try out cleaning current debt[i], by
 * debt[j] += debt[i] where debt[i] and debt[j] has diffrent sign.
 * and count it as one operation
 * 
 * Recursively checking all possible combination of transactions to get 
 * the smallest transactions needed
 */

class Solution {
    vector<int> debt;
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long long> mp;
        for(auto& p: transactions){
            mp[p[0]] -= p[2];
            mp[p[1]] += p[2];
        }
        for(auto p: mp){
            debt.push_back(p.second);
        }
        return dfs(0);
    }
    
    int dfs(int idx){
        while(idx < debt.size() && debt[idx] == 0) idx++;
        int res = INT_MAX;
        for(int i = idx + 1, prev = 0; i < debt.size(); i++){
            if(debt[i] * debt[idx] < 0 && prev != debt[i]){
                debt[i] += debt[idx]; // clear debt[idx];
                res = min(res, 1 + dfs(idx+1));
                prev = debt[i] -= debt[idx];
            }
        }
        return res == INT_MAX? 0: res;
    }
};