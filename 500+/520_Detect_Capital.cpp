/* 520. Detect Capital
 * Count the number of capital letters, checking if it belongs to one of the rules
 * of being a valid one
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capnum = 0;
        for(int i = 0; i < word.length(); i++){
            if(word[i] < 'a') capnum++;
        }
        
        if(capnum == 0) return true;
        if(capnum == 1 && word[0] < 'a') return true;
        if(capnum == word.length()) return true;
        
        return false;
    }
};