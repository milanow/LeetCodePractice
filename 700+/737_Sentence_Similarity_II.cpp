/* 737. Sentence Similarity II
 * A typical union-find problem. Connecting similar words together by group
 * And then check if two words from words1 & word2 belong to same group
 */

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n1 = words1.size(), n2 = words2.size();
        if(n1 != n2) return false;
        
        unordered_map<string, string> parents;
        // set words' parent to its own
        for(auto& p: pairs){
            parents[p.first] = p.first;
            parents[p.second] = p.second;
        }
        // union words
        for(auto& p: pairs){
            string p1 = root(parents, p.first), p2 = root(parents, p.second);
            if(p1 != p2){
                parents[p1] = p2;
            }
        }
        // check words1 and words2
        for(int i = 0; i < n1; i++){
            string p1 = root(parents, words1[i]), p2 = root(parents, words2[i]);
            if(p1 != p2) return false;
        }
        return true;
        
    }
    
private:
    string root(unordered_map<string, string>& parents, string key){
        while(key != parents[key]){
            key = parents[key] = parents[parents[key]];
        }
        return key;
    }
};