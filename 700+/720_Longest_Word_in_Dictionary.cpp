/* 720. Longest Word in Dictionary
 * The key is to find out (1)if the substring(0, sz-1) of a word (in words)
 * is also in words
 * 
 * Sorting the words first and save previous qualified words (meets (1) in a set
 * checking if current word's substring(0, sz-1) also inside the set
 */

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};