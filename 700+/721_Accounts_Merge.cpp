/* 721. Accounts Merge
 * A Union-Find solution. If two accounts have same email address, union them together
 * Detailed explaination can be found at comments
 */

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Union-Find
        unordered_map<string, string> parents;
        unordered_map<string, string> owners;
        unordered_map<string, set<string>> res;
        
        // Set nodes' parents to themselves
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                parents[accounts[i][j]] = accounts[i][j];
                owners[accounts[i][j]] = accounts[i][0];
            }
        }
        
        // for every account, set the first email's parent to be the parent of rest emails
        for(int i = 0; i < accounts.size(); i++){
            string p = root(accounts[i][1], parents);
            for(int j = 2; j < accounts[i].size(); j++){
                parents[root(accounts[i][j], parents)] = p;
            }
        }
        
        // Union accounts together
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                res[root(accounts[i][j], parents)].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> ans;
        // Convert res to output format
        for(auto& p: res){
            vector<string> account(p.second.begin(), p.second.end());
            account.insert(account.begin(), owners[p.first]);
            ans.push_back(account);
        }
        
        return ans;
    }

private:
    string root(string k, unordered_map<string, string>& parents){
        while(parents[k] != k){
            k = parents[k] = parents[parents[k]];
        }
        return k;
    }
};