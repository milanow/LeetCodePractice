/* 734. Sentence Similarity
 * Save the words' relationships in a map, and checking words one by one
 * to see if all words pairs are in the map
 */

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int len1 = words1.size();
        int len2 = words2.size();
        unordered_map<string, unordered_set<string>> mp;
        for(auto& p: pairs){
            mp[p.first].insert(p.second);
            // mp[p.second].insert(p.first);
        }
        
        if(len1 != len2) return false;
        for(int i = 0; i < len1; i++){
            if(words1[i] == words2[i]) continue;
            if(mp[words1[i]].find(words2[i]) == mp[words1[i]].end() && mp[words2[i]].find(words1[i]) == mp[words2[i]].end()) return false;  
        }
        return true;
    }
};