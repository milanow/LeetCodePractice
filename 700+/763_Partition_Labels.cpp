/* 763. Partition Labels
 * Much more like a greedy algorithm
 * Firstly, saving the character and its frequency in a diction (vector<int>(26)).
 * Then iterating through the string, once all characters appearing before the index
 * have the same frequency of the dict, then it is to say this sub-string can be partioned
 */

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> dict(26, 0);
        for(int i = 0; i < S.length(); i++){
            dict[S[i] - 'a']++;
        }
        
        vector<int> res;
        unordered_map<int, int> mp;
        int start = -1;
        for(int i = 0; i < S.length(); i++){
            mp[S[i]-'a']++;
            bool match = true;
            for(auto& p: mp){
                if(dict[p.first] != p.second){
                    match = false;    
                }
            }
            if(match){
                res.push_back(i - start);
                start = i;
            }
        }
        return res;
    }
};