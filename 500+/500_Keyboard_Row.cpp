/* 500. Keyboard Row
 * Set three group (hashset) to store each rows on the keyboard
 * Check if the word where all characters belong to any one of the hashset
 */

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> st1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> st2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> st3{'z','x','c','v','b','n','m'};
        
        vector<string> res;
        for(auto& word: words){
            int i;
            if(st1.find(tolower(word[0])) != st1.end()){
                for(i = 1; i < word.size(); i++){
                    if(st1.find(tolower(word[i])) == st1.end()) break;
                }
            }else if(st2.find(tolower(word[0])) != st2.end()){
                for(i = 1; i < word.size(); i++){
                    if(st2.find(tolower(word[i])) == st2.end()) break;
                }
            }else if(st3.find(tolower(word[0])) != st3.end()){
                for(i = 1; i < word.size(); i++){
                    if(st3.find(tolower(word[i])) == st3.end()) break;
                }
            }
            if(i == word.size()) res.push_back(word);
        }
        return res;
    }
};